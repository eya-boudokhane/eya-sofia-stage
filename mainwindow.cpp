#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QLayout>
#include <QTextEdit>
#include <QInputDialog>
#include <QProgressBar>
#include <QTimer>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <fstream>
#include <unistd.h>
#include <QDebug>
using namespace std;



const int NUM_CPU_STATES = 10;
#include <QTextStream>
#include  <QMessageBox>
#include <QProgressBar>
#include <QString>
#include <QLabel>
#include <unistd.h>
#include <QHBoxLayout>
#include <QWidget>
extern "C"{
    #include <sys/statvfs.h>
}

#define HAVE_REMOTE
#include "/usr/include/pcap/pcap.h"
#include <iostream>
#include <fstream>
#define snprintf _snprintf
#define IPTOSBUFFERS    12
#include <sstream>
#include <string>
#include <QColor>
#pragma warning(disable : 4996)

using namespace std;
enum CPUStates
{
    S_USER = 0,
    S_NICE,
    S_SYSTEM,
    S_IDLE,
    S_IOWAIT,
    S_IRQ,
    S_SOFTIRQ,
    S_STEAL,
    S_GUEST,
    S_GUEST_NICE
};

typedef struct CPUData
{
    std::string cpu;
    size_t times[NUM_CPU_STATES];
} CPUData;

void ReadStatsCPU(std::vector<CPUData>& entries);

size_t GetIdleTime(const CPUData& e);
size_t GetActiveTime(const CPUData& e);

void PrintTotalStats(const std::vector<CPUData>& entries1, const std::vector<CPUData>& entries2);


void ReadStatsCPU(std::vector<CPUData>& entries)
{
    std::ifstream fileStat("/proc/stat");

    std::string line;

    const std::string STR_CPU("cpu");
    const std::size_t LEN_STR_CPU = STR_CPU.size();
    const std::string STR_TOT("tot");

    while (std::getline(fileStat, line))
    {
        // cpu stats line found
        if (!line.compare(0, LEN_STR_CPU, STR_CPU))
        {
            std::istringstream ss(line);

            // store entry
            entries.emplace_back(CPUData());
            CPUData& entry = entries.back();

            // read cpu label
            ss >> entry.cpu;

            // remove "cpu" from the label when it's a processor number
            if (entry.cpu.size() > LEN_STR_CPU)
                entry.cpu.erase(0, LEN_STR_CPU);
            // replace "cpu" with "tot" when it's total values
            else
                entry.cpu = STR_TOT;

            // read times
            for (int i = 0; i < NUM_CPU_STATES; ++i)
                ss >> entry.times[i];
        }
    }
}

size_t GetIdleTime(const CPUData& e)
{
    return	e.times[S_IDLE] +
        e.times[S_IOWAIT];
}

size_t GetActiveTime(const CPUData& e)
{
    return	e.times[S_USER] +
        e.times[S_NICE] +
        e.times[S_SYSTEM] +
        e.times[S_IRQ] +
        e.times[S_SOFTIRQ] +
        e.times[S_STEAL] +
        e.times[S_GUEST] +
        e.times[S_GUEST_NICE];
}

void MainWindow::updateProgress()
{
    //progressBar->setValue(progressBar->value()+1);

        std::vector<CPUData> entries1;
        std::vector<CPUData> entries2;

        // snapshot 1
        ReadStatsCPU(entries1);

        // 100ms pause
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // snapshot 2
        ReadStatsCPU(entries2);

        // print output
        //PrintTotalStats(entries1, entries2);
        const CPUData & e1 = entries1[0];
        const CPUData & e2 = entries2[0];
        const float ACTIVE_TIME = static_cast<float>(GetActiveTime(e2) - GetActiveTime(e1));
        const float IDLE_TIME = static_cast<float>(GetIdleTime(e2) - GetIdleTime(e1));
        const float TOTAL_TIME = ACTIVE_TIME + IDLE_TIME;
        auto cpusage = 100.f * ACTIVE_TIME / TOTAL_TIME;

        // mise à jour de progressBar
        ui->progressBar->setValue(cpusage);

}




char *iptos(u_long in);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        QHBoxLayout *layout = new QHBoxLayout();
        setLayout(layout);

        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::updateProgress);
        timer->start(1000);
        ui->progressBar->setMinimum(0);
        ui->progressBar->setMaximum(100);
     ui->progressBar->setValue(50);
     QLabel *textBrowser_5 = new QLabel(this);
     int tSize = 0, resident = 0, share = 0;
     ifstream buffer("/proc/self/statm");
     buffer >> tSize >> resident >> share;
     buffer.close();

     long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
     double rss = resident * page_size_kb;
     double shared_mem = share * page_size_kb;

     ui->textBrowser_5->setText("Resident Set Size=  " + QString::number(rss) +"  kB/n"+ QString("\n") + "Shared Memory=  "+
                    QString::number(shared_mem)+ "  kB/n"+ QString("\n")+
                   "Private Memory=  " +QString::number(rss - shared_mem)+ "  kB/n");

}

MainWindow::~MainWindow()
{
    delete ui;
}

long GetAvailableSpace(const char* path)
{
  struct statvfs stat;

  if (statvfs(path, &stat) != 0) {
    // error happens, just quits here
    return -1;
  }

  // the available size is f_bsize * f_bavail
  return stat.f_bsize * stat.f_bavail;
}
QString sys()
{long byte   = GetAvailableSpace("/");
          long kilo   = byte / 1024;
          long mega   = kilo / 1024;
          long giga   = mega / 1024;

         return (QString) "Available Space: " + QString ::number(giga) + " GB." + "\n";

         }






void MainWindow::on_pushButton_pressed()
{
    QFile file ("/sys/class/net/enp0s3/address");
    if (!file.open(QIODevice::ReadOnly))
   QMessageBox::information(0,"info",file.errorString());
           QTextStream in(&file);
            ui->textBrowser->setText("Mac Address: "+in.readAll());
            pcap_if *all_devs;
            pcap_if_t* single_dev;
            char* errbuff[PCAP_ERRBUF_SIZE];
            int getdevs = pcap_findalldevs(&all_devs, *errbuff);
            if(getdevs == -1) { cout << "Erreur" << endl; }

            single_dev = all_devs;

            while(single_dev != NULL)
            {
                auto a = single_dev->addresses;
                        while(a != NULL)
                        {
                            switch(a->addr->sa_family)
                            {
                                case AF_INET:
                                { QString x;
                                x=inet_ntoa(((struct sockaddr_in *)a->addr)->sin_addr);
                                    cout << inet_ntoa(((struct sockaddr_in *)a->addr)->sin_addr) << endl;
                                    ui->textBrowser_3->append("IP address:"+QString("\n")+x);
                                    break;
                                }
                            }
                          a = a->next;

                        }

              single_dev = single_dev->next;
            }
            QFile file3 ("/sys/class/net/enp0s3/operstate");
            if (!file3.open(QIODevice::ReadOnly))
           QMessageBox::information(0,"info",file3.errorString());
                   QTextStream on(&file3);
                    ui->textBrowser_2->setText("Port Status: "+on.readAll());
}

void MainWindow::on_pushButton_2_pressed()
{
    ui->textBrowser_4->setText(sys());
}
