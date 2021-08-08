 # QT applications for CPU Usage and Memory Info:
## Project Description:
 This project consists of creating a QT application that displays:
 *The percentage of the CPU Used in Real-Time
 *The system memory info: the resident set size, the private memory and the shared memory
 *Network informations (IP addresses/Mac Address/Interface status)
 *The Disk Usage
 
 ## Table of content:
 1. What is QT?
 2. Enviornment requirements
 3. How to run
 4. How to compile
 5. The application
 
### 1.What is QT?
Qt is a commercial and open source licensed cross-platform application and UI framework. It is developed by The Qt Company, together with the Qt Project Community under an open-source governance model. Using Qt, you can write GUI applications once and deploy them across desktop, mobile, and embedded operating systems without rewriting the source code 
 
### 2.Environment requirements:
The Qt API is implemented in C++, and provides additional features for easier cross-platform development and it is supported on a variety of 32-bit and 64-bit platforms
 The Supported Platforms include Linux, OS X, Windows, VxWorks, QNX, Android, iOS, BlackBerry, Sailfish OS and others.
 
 ![logo Qt](https://user-images.githubusercontent.com/60946152/125640362-483b50c3-be40-44f4-9d88-4114c3310a9c.png)
 
For my case, I’ve worked with Linux, and as I have a Windows machine, I have installed  Oracle VM Virtual Box and Ubuntu 20.04 (Focal).
https://www.virtualbox.org/
![Virtualbox_logo](https://user-images.githubusercontent.com/60946152/125640732-1519a720-c4c7-414f-98e0-87c9e5b53974.png)

To download Ubuntu Focal : https://releases.ubuntu.com/20.04/ (download file.iso) and here’s a simple Tutorial that helped me to install it https://www.youtube.com/watch?v=pBayDTZC2EE&t=3s&ab_channel=LinuxHelp
![2560px-Former_Ubuntu_logo svg](https://user-images.githubusercontent.com/60946152/125647670-b237b514-7ca8-4564-afa4-38f72bdb68f7.png)
![Capture d’écran 2021-07-14 162305](https://user-images.githubusercontent.com/60946152/125648267-3bc6c56b-a225-4e49-978a-a11afe72a5a9.png)


After finishing installing VirtualBox and Ubuntu, we need to start our Machine and then open the Terminal and enter these command lines in order to install QT:

![Capture d’écran 2021-07-14 162715](https://user-images.githubusercontent.com/60946152/125649230-cf27e3e7-1240-456d-9682-4a91d2356d9e.png)
```ssh
sudo apt install qtcreator -y
sudo apt install build-essential
sudo apt install qt5-default

```


![QT-Ubuntu](https://user-images.githubusercontent.com/60946152/125772099-7acb035f-abc9-4588-a86e-8f4e85212fb8.PNG)
### 3.How to compile:
After installing QT, you need to install the ZIP file of this project and extract it to a directory.
![Extraction du dossier](https://user-images.githubusercontent.com/60946152/125772986-68160662-5a9e-47b7-bfcc-e35e4066509f.PNG)

Then, you should open QT Creator and click on File/Open a file or a project:

![open a file or a project](https://user-images.githubusercontent.com/60946152/125775097-815c1ceb-0ab8-4b47-b16b-a8811e2f9f32.png)

And you need to select the project that you've extracted.
### 4.How to run:

After compiling the CPU Usage project and making sure that there are no problems in your code, click on RUN (Marked in Red)

![How to compile](https://user-images.githubusercontent.com/60946152/125783062-b2429619-bf7f-4272-902b-a937fa72ee05.png)

### 5.The application:
After opening the project and running it, a window containing Push buttons (one for the Disk Space and another for the network informations), a progress bar to show the percentage of the CPU used and the system memory informations.

![1](https://user-images.githubusercontent.com/60946152/128646365-d9a2864d-2399-4ff6-9efb-a4dfbf60f69f.png)

![2](https://user-images.githubusercontent.com/60946152/128646371-be623328-e961-46a3-8f78-d2037899a54c.png)





