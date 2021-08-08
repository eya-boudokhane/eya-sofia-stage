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

Then, you should open QT Creator and click on File/Open a file or a project:

![open a file or a project](https://user-images.githubusercontent.com/60946152/125775097-815c1ceb-0ab8-4b47-b16b-a8811e2f9f32.png)

And you need to select the project that you've extracted and click on the button Build marked in RED

![image](https://user-images.githubusercontent.com/60946152/128646474-19d65c4d-e43d-4624-9ed2-adb556b6a858.png)


### 4.How to run:

After compiling the CPU Usage project and making sure that there are no problems in your code, click on RUN (Marked in Red)

![image](https://user-images.githubusercontent.com/60946152/128646592-43b20596-649d-42a0-80df-a4b4b8960f22.png)


### 5.The application:
After opening the project and running it, a window containing Push buttons (one for the Disk Space and another for the network informations), a progress bar to show the percentage of the CPU used and the system memory informations.

![image](https://user-images.githubusercontent.com/60946152/128647186-d5f680d6-a1b1-45ee-8e61-4dcc87299b6d.png)

Click on the button Disk space and Network informations:

![image](https://user-images.githubusercontent.com/60946152/128647200-28e2d6c8-f9bb-4748-9a67-eaadc3f53d70.png)





