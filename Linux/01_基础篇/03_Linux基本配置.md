# Linux基本配置
## 关于超级用户root
- 所有的系统设置都需要root用户来完成，即超级用户，也叫做根用户。
  - 权限：是整个系统中拥有最高权限的用户，root用户可以做任何事情。root可以访问、修改、删除系统中的任何文件和目录;
  - Linux系统上的每个文件和目录都属于某个特定的用户(在多人协作的服务器上)，没有得到许可，其他用户就不能访问，但是root用户可以访问所有用户的文件;
  - 用户可以执行不带参数的`su`命令将自己提升为root权限（当然需要提供root口令）;而`sudo` 可以临时使用root身份运行程序，并在执行完毕后返回至普通用户状态;
  - 对绝大多数Linux发行版，安装最后一步会设置root和普通用户。而对于Debian和Ubuntu系统，只有一个普通用户+sudo来执行root权限。但是，sudo是通过读取`etc/sudoers`来确定什么用户可以在什么机器上执行什么命令;
  - `sudo -s`可以将自己提升为root用户，相当于`su`命令，用`exit`退出。
## 系统管理
- 图形化管理界面只在系统正常时可以使用，命令行往往更可靠和灵活。
## 进阶：配置Grub
- Grub(多重引导程序)启动时通常从`/boot/grub/grub.cfg`读取引导配置，并且严格地依此行事。查看该文件，开头会提示*不要编辑该文件*，因为该文件是以`/etc/default/grub`作为配置自动生成的。
  - 但是`/boot/grub/grub.cfg`并不是不可以更改的，也可以直接移动引导项的代码来改动引导项(如windows)。
- `/etc/default/grub`(修改后需执行'update-grub'生效)中的参数：
  - GRUB_DEFAULT:引导项列表的*默认选择项序号*(从0开始);
  - GRUB_TIMEOUT:引导项列表自动选择超过时间(超过则默认选中);
- 还可以在Grub启动画面出现时按下C键可以进入Grub的命令行模式。
| 命令 | 说明 |
| --- | --- |
| help | 显示帮助信息 |
| reboot | 重新引导系统 |
| root | 指定根分区 |
| kernel | 指定内核所在位置 |
| find | 在所有可以安装的分区上寻找一个文件 |
| boot | 依照配置引导系统 |
## 桌面
- Linux不是一种基于图形环境的操作系统，在内核眼里，图形环境只是一个普通的应用程序。
- X窗口系统(X Window System)是Linux图形用户环境的基础。如今绝大多数Linux使用的是由X.org基金会维护的X.Org。
- X系统基于一种独特的服务器/客户机架构：
  - 意味着一台主机上的X应用程序可以在另一台主机的屏幕上显示出来，X服务器接受来自多个应用程序请求，然后在本地显示。
- X窗口系统的基本组成：
  - **X服务器**:
	- X服务器用于实际控制输入设备(如鼠标和键盘)和位图式输出设备(如显示器)，X服务器定义了给X客户机使用这些设备的抽象接口，X服务器没有定义高级实体的编程接口(语法上还是比较低级);
	- X服务器要做到最大程度上的与平台无关，用户可以选择窗口管理器和widget库来定制自己的桌面，而不需要改变底层配置。
  - **X客户端程序**:
	- 需要向X服务器请求服务的程序就是X客户端程序;
	- 它们运行时需要把自己的长相描述给X服务器，由X服务器负责在显示器上绘制这些应用程序的界面。
  - **窗口管理器(Window Manager)**:
	- 窗口管理器负责控制应用程序窗口的各种行为(如缩放等);
	- 是一种特殊的X客户端程序。
  - **显示管理器(Display Manager)**:
	- 显示管理器提供了一个登录界面，用于验证用户身份，让用户登录到系统;
	- 图形界面的一切(除了它自己)都是由这个显示管理器启动的，包括X服务器;
	- 从命令行启动X服务器`startx`。
  - **widget库**:
	- 定义了一套图形用户界面的编程接口;
	- 通过调用widget库来实现具体的用户界面;
	- wiidget库会自动把高级语言翻译成X服务器可以理解的语言。
  - **桌面环境**:
	- 桌面环境是把各种与X有关的东西(除了X服务器);
	- 处理图形输出的始终是X服务器。
- X系统的启动过程：
  - X系统的启动过程是由显示管理器(Display Manager)完成的，显示管理器启动后依次完成以下工作：
	- 启动X服务器;
	- 提供一个界面友好的屏幕，等待和验证用户身份;
	- 执行用户的**引导脚本**，该脚本用于建立用户的桌面环境。
	  - 桌面环境的引导脚本是一段用Linux命令组成的脚本程序，叫Xsession;	
	  - Xsession通过启动窗口管理器、任务栏，设定应用的默认值、安装标准键绑定来启动整个桌面环境;
	  - Xsession会一直运行，直到用户退出(也Xsession运行结束时，用户就退出了);
	  - 窗口管理器是Xsession启动的唯一前台程序，如果没有这个前台程序，用户会在登录后又退出系统。
- KDE：
  - KDE是基于C++编写的，基于Qt库;
  - KDE编写的程序总是带着一个字母K。
- Gnome：
  - Gnome使用C语言写成，基于GTK+widget库;
  - Gnome程序大多带着一个字母G。
- `/etc/X11/xorg.conf`：X服务器的配置文件;
  - 如果显卡出现问题，可以通过修改xorg.conf禁用已有的显卡驱动程序。
