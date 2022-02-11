# Linux基础篇

### 虚拟机安装和系统安装

* 安装VMware和CentOS7.6

  * **linux的分区**
    * boot区：用于引导操作系统启动
    * swap区：用于内存扩展（内存虚拟），大小一般与内存大小相同
    * 根目录区：操作系统主文件

  * 操作系统的克隆
    * 直接拷贝一份已经安装好的操作系统文件，利用虚拟机自动识别
    * 利用VMware提供的克隆功能，需要先关闭当前操作系统

* 虚拟机快照

  快照管理：使用OS时，怕操作失误而想回到失误之前的状态

  使用实例

  * 安装好系统，先做一个快照A

    虚拟机--->快照--->拍摄快照

  * 进入系统，创建一个文件夹，再保存一个快照B

    快照管理---->选择需要回到的快照

  * 回到系统刚刚安装好的状态，即快照A

    当存在多个快照时，可以相互之间跳转

* 安装vmtools

  ---百度吧---

***

### Linux的目录结构

在Linux世界里，一切皆文件

* 具体的目录结构
  * /bin : [常用]（/usr/bin、/usr/local/bin） 是Binary的缩写，存放最近常用使用的命令
  * /sbin ：（/usr/sbin、/usr/local/sbin）s就是super user，存放系统管理员使用的系统管理程序
  * /home ：[常用] 存放普通用户的主目录，在Linux中，每个赢回都有一个自己的目录，一般该目录名是以用户的账户号命名
  * /root：[常用] 该目录为系统管理员，也称作超级权限者的用户主目录
  * /lib : 系统开机最基本的动态连接共享库，作用类似以Windows的DLL文件，几乎所有的应用程序都需要实用这些共享库
  * /lost+found ： 一般是空的，当系统非法关机后，在这里存放一些文件
  * /etc ： [常用] 所有的系统管理所需要的配置文件和子目录
  * /usr ： [常用] 非常重要，用户的很多应用程序和文件都放在这个目录下，类似于Windows的program files目录
  * /boot   : [常用] 存放的是启动Linux时使用的一些核心文件，包含一些连接文件一级镜像文件
  * /proc ： 【不能动】是一个虚拟的目录，它是系统内存的映射，访问这个目录来获取系统信息
  * /srv ：  service的缩写，存放一些与服务启动之后需要提取的数据
  * /sys : 这是；inux 2.6内核的一个很大的变化，安装了2.6内核中新出现的一个文件系统sysfs
  * /tmp : 存放一些临时文件
  * /dev : 类似与Windows的设备管理器，把所有硬件以文件的形存储
  * /media : [常用] Linux系统会自动识别一些设备，比如U盘等，识别后会挂载到这个目录
  * /mnt : [常用] 该目录是为了让用户临时挂载别的文件系统的，可以将外部的文件挂载在/mnt/上。然后进入该目录就可以查看里面的内容了
  * /opt : 给主机额外**安装软件包**所摆放的目录，如安装ORAClE数据库可以放到该目录下，默认为空
  * /usr/local :  [常用],额外的软件安装目录,一般是通过编译源码方式安装的程序
  * /var : [常用] 这个目录存放着不断扩充的东西,习惯将经常倍修改的目录放在这个目录下,包括各种日志文件
  * /selinux : [security-enhanced linux] 安全子程序,只能访问特定文件,有三种工作模式,可自行设定

***

# Linux实操篇(上)

### 远程登陆到Linux服务器

* 登陆客户端有Xshell,Xftp6

  ---

  

### vi和vim

linux 会内置vi文本编辑器

vim 具有程序编写能力,可以看作是vi的增强版本,具有代码高亮,补完,编译及错误跳转等功能

* **常用的三种模式**
  * 正常模式: 正常打开进入就是默认模式,移动光标,删除字符或整行删除,也可以使用粘贴复制
  * 插入模式 : 按下i,I,o,O,a,A,r,R等任何一个字母之后才会进入编辑模式,一般按i
  * 命令行模式 ; 在这个模式中,可以完成相关指令,完成读取,存盘,替换,离开vim,显示行号等

* **三种模式的切换**

  * 在命令行下:vim xxx进入xxx文件,进入正常模式

  * 输入i 后可以编辑,完成后按wsc 返回正常模式

  * 输入 :  或者 /  进入命令模式,有三种命令

    :wq   保存退出;

    :q   退出

    :q!   强制退出,不保存

* **快捷键的使用**

  * 拷贝当前行  yy, 拷贝当前行向下的5行   5yy, 并粘贴[输入p]

  * 删除当前行  dd, 删除当前行向下的5行  5dd

  * 在文件中查找某个单词[**命令行** /关键字--->回车 查找 --->输入n就是查找下一个]

  * 设置文件的行号,取消文件的行号.[命令行下:set nu 和 : set nonu]

  * 编辑 /etc/profile 文件,使用快捷键到该文档的最末行:[正常模式]下使用[G]和最首行[gg]

  * 在一个文件中输入"hello",然后有撤销这个动作:[一般模式] u

  * 编辑 /etc/profile 文件,并将光标移动到 20 行 :[一般模式] 输入行号(20),再输入shift + g

  * 其它快捷键参见快捷键图或者文档:vim命令大全

    ***

    

### 开机,重启和用户登陆注销

* 基本介绍
  * shutdown -h nuw	**立刻关机**
  * shutdown -h 1       **1分钟后关机**:会给连接到本系统的用户都发送一条通知消息
  * shutdown -r now      **立即重启**
  * shutdown    等同于"shutdown -h 1"
  * halt     **关机**
  * reboot   **立刻重启计算机**
  * sync   **把内存数据同步到磁盘**

注意: 不管是重启系统还是关机,都要先运行sync命令,把内存中的数据西岛磁盘中

​		目前的shutdown/reboot/halt 等命令已经再关机前进行了sync命令

* 用户登陆和注销

  * 一般尽量别使用root账号登陆,使用普通用户登陆,如有需要使用"su - root"切换进root账号

  * 使用logout注销用户登录状态

    logout注销指令在图形运行级别无效,在"运行级别"3下有效

  * 在图形界面下使用的终端,输入exit退出终端,输入logout不起作用;如果是普通用户,使用"su - root"命令切换到root用户,使用完后可使用logout退回到普通用户

* 添加用户

  * 基本语法

    **useradd 用户名**

  * 当创建用户成功后,会自动创建和用户同名的家(home)目录

  * 也可以通过"**useradd -d  指定目录 新的用户名**",给新创建的用户指定家目录

* 设置密码

  * 基本语法

    passwd 用户名

  > 补充:pwd命令可以显示你当前所在目录

* 删除用户

  * 基本语法

    userdel 用户名

    必须使用root用户才能操作

  * 删除用户,但要保留家目录   "userdel 用户名"

  * 删除用户及用户主目录   "userdel -r 用户名"

    > 是否保留家目录的讨论:
    >
    > 一般情况下建议保留, 

* 查询用户信息

  * 基本语法

    id 用户名

    当用户不存在时,返回无此用户

* 切换用户

  * 基本语法

    su - 用户名

  * 从权限高的用户切换到权限低的用户,不需要输入密码,反之需要
  * 当需要返回原来的用户时,使用exit/logout指令

* 查看当前用户信息

  * who am i

    返回当前用户信息,是第一次登陆的用户,不会返回使用su - 命令登陆的用户

* 用户组

  设置具有共性/权限的多个用户进行统一管理

  **操作**

  * 新增组: **groupadd 组名**

  * 删除组: **groupdel 组名**

  * 新增用户是直接分配组:  **useradd -g 用户组 用户名**

    > 如果新增用户时,未声明组名,则系统会默认以用户名为组名新建一个组并把新增的用户放入组中

  * 修改用户的组: usermod -g 用户组 用户名

* 用户和组相关的文件

  * /ect/passwd 文件

    用户(user)的配置文件,记录用户的各种信息

    含义:用户名:口令(passwd):用户标识符(uid):组标识符(gid):注释性描述:主目录:登陆shell

  * /ect/shadow 文件

    口令的配置文件

    含义:登录名:加密口令:最后一次修改时间:最小时间间隔:最大时间间隔:警告时间:不活动时间:失效时间:标志

  * /ect/group 文件

    组(group)的配置文件,记录Linux包含的组的信息

    含义:组名:口令:组标识号:组内用户列表

***

### 实用指令

* 指定运行级别

  * 运行级别说明：

    * 0：关机

    * 1：单用户（可以在此模式下找回丢失密码）

    * 2:多用户状态没有网络服务（几乎没用）

    * 3:多用户状态有网络服务（最常用）

    * 4:系统未使用保留给用户（几乎不用）

    * 5:图形界面

    * 6:系统重启

      常用的级别时3和5，也可以指定默认运行级别

  * 应用实例

    命令：init [0~6]

    案例：通过init来切换不同的运行级别

  * 指定运行级别

    centos7后运行级别说明：

    在/etc/inittab文件中，有如下：

    >multi-user.target:analogous to runleve 3
    >
    >graphical.target:analogous to runleve 5
    >
    >
    >
    >#To view current default target,run:(查看当前默认级别)
    >
    >systemctl get-default
    >
    >
    >
    >#To set a default target,run:
    >
    >systemctl set-default TARGET.target

    

* 找回root密码（CentOS7以上版本）

  * 启动系统，进入开机界面，迅速按“e”进入编辑界面

  *  在编辑界面，使用键盘移动光标，找到“Linux16”开头内容所在的行数，在行的最后(UTF-8附近)面输入："init=/bin/sh"

  * 输入后，按快捷键：Ctrl+x ，系统会重启进入单用户模式

  * 在光标闪烁的位置输入：“mount -o remount,rw /”（注意：各个单词之间有空格，有个‘/’不要忘记），完成后按回车

  * 在新的一行的最后面输入：“passwd”,完成后回车。输入密码，然后再次确认密码即可，修改成功后，会显示...passwd...的样式

  * 接着，在光标闪烁的位置（最后一行）输入：

    “touch /.autorelabel”（注意：touch与 / 之间有空格），完成后按回车

  * 继续在光标闪烁的位置，输入："exec /sbin/init"（注意：exec与 / 之间有空格），完成后回车等待，系统会自动重启（此过程有点长耐心等待）

* 帮助指令

  * man 获取帮助指令

    基本语法: man [命令或配置文件] （功能描述：获得帮助信息）

    实例：查看ls:man ls

    > ls 命令查看文件夹内的文件一级文件夹，其可以带参数
    >
    > ls -a:列出所有文件，包括“.”开头的隐藏文件
    >
    > ls -l:文件按行显示，附带文件属性信息
    >
    > 也可以组合使用，如：ls -la
    >
    > 可以指定目录，如：ls -al /home

    查看结束可以之间按“q”退出

  * help 指令

    基本语法：help 命令 （功能描述：获得shell内置命令的帮助信息）

* 文件目录类

  * pwd指令

    显示当前工作目录的绝对路径

  * ls 指令

    格式：ls [选项] [目录或文件]

    常用选项：

    -a ：显示当前所有文件和目录，包括隐藏

    -l：以列表形式显示文件信息

    -lh:文件大小以M，G等为单位显示

  * cd 指令

    格式：cd [参数]

    "cd ~"或者"cd"：回到自己的家目录

    “cd ..”：回到当前目录的上一级目录

  * mkdir指令

    用于创建目录

    格式：mkdir [选项] ：要创建的目录

    mkdir -p [路径] ：创建多级目录

    > touch 指令可以创建一个文件：touch [文件名]
    >
    > vim 可以创建一个文件并打开文件进行编辑

  * rmdir指令

    用于删除空目录

    格式：rmdir [选项] [要删除的空目录]

    rmdir删除的是空目录，如果目录下面有内容时无法删除

    如果要删除非空目录，需要使用：“rm -rf [要删除的目录]”

  * cp 指令

    cp 指令拷贝文件到指定目录

    格式：cp [选项] 源文件 目标文件夹/

    -r: 递归复制整个**文件夹**

    强制覆盖不提醒：\cp

  * rm指令

    用于移除文件或者目录

    格式：rm [选项] [文件名/目录名]

    -r：递归删除整个文件夹

    -f：强制删除不提示

  * mv指令

    用于移动文件与目录或重命名

    格式：mv [原文件名] [新文件名]    重命名

    ​			mv  [源文件] [目标文件]      移动文件 	 	

  * cat指令

    用于查看文件内容

    格式：cat [选项] [文件名]

    -n：显示行号

    cat只能浏览文件，不能修改文件，为了浏览方便，一般会带上 管道命令 | more

  * less 指令

    用来分屏查看文件内容，它的功能与more指令类似，但是比more指令更加强大，支持各种显示终端。less指令在显示问价内容时，并不是一次将整个文件加载之后才显示，而是更具显示需要加载内容，对于显示大型问价具有较高的效率

    格式：less [文件名]

    操作说明：

    * 空格键		---->向下翻译一页
    * [pagedown]--->向下翻动一页
    * [pageup]      --->向上翻动一页
    * /[字串]        --->向下搜索[字串];n:向下查找；N:向上查找
    * ？[字串]       --->向上搜索[字串]；n:向上查找；N:向下查找
    * q       --->离开less程序

  * echo指令

    输出内容到控制台

    格式：echo [选项] [输出内容]

    > 输出环境变量$PATH  或者 $HOSTNAME

  * head 指令

    用于显示文件的开头部分内容，默认情况下head指令显示文件的前10 行内容

    格式：head [文件名]     查看文件的头10 行

    head -n 5 [文件名]    查看文件头5行内容

  * tail 指令

    用于输出文件的中尾部的内容，默认情况下tail显示文件后10行内容

    格式：1、tail [文件名]   （查看文件尾部10行）

    2、tail -n 5 [文件名]  （产看尾部5行内容）

    3、tail -f [文件名]   （实时追踪该文件的所有更新）

  * '>'指令和‘>>’指令

    ‘>’为重定向指令；‘>>’指令为追加指令

    格式：1、ls -l >[文件名]  （列表的内容写入文件a.txt中，覆盖掉）

    2、ls -al >>[文件名] （列表的内容追加到a.txt文件的末尾）

    3、cat [文件1] > [文件2]  （将文件1的内容覆盖到文件2）

    4、echo "内容" >> [文件名]

  * ln 指令

    软连接，也称为符号链接，类似于windows的快捷方式，主要存放了连接其他文件的路径

    格式：ln -s [源文件或目录] [软链接名] （给原文件创建一个软连接）

    当使用pwd指令查看目录时，仍然看到的时软连接所在的目录

    使用rm 指令删除不需要的软连接

  * history指令

    查看已经执行过的历史命令，也可以执行历史指令

    格式：1、history（查看已经执行过的历史命令）

    2、history 10 （查看最近执行过的10 个命令）

    3、!5（执行历史编号为5的指令）

* 时间日期类

  * date指令  --显示当前日期

    格式：

    * date  （显示当前时间）
    * date +%Y （显示当前年份）
    * date +%m（显示当前月份）
    * date +%d（显示当前时哪一天）
    * date "+%Y-%m-%d %H:%M:%S"（显示年月日时分秒）
    * date +%F （格式化显示年月日）

  * date指令----设置日期

    格式：date -s [字符串时间]

  * cal 指令---查看日历

    格式：cal [选项]  （不加选项显示本月日历）  

* 搜索查找类

  * find指令

    从指定目录向下递归遍历各个子目录，将满足条件的我呢见 或者目录显示在终端

    格式：find [搜索范围] [选项]

    * -name [查询方式] :按照指定的文件名查找模式查找文件

    * -user [用户名]：查找属于指定用户名所有文件

    * -size [文件大小n]：按照指定的文件大小查找文件

      +n:大于；-n:小于;n:等于

  * locat 指令

    可以快速定位文件路径。locate指令利用事先建立的系统中所有文件名称及路径的locate数据库实现快速定位给定的文件。locate指令无需遍历整个文件系统，查询速度较快，为了保证查询结果的准确度，管理员必须定期更新locate时刻

    格式：locate [文件名]

    > 由于locate 指令基于数据库进行查询，所以第一次运行前，必须使用updatedb指令创建locate数据库
    >
    > which 指令，可以查看某个指令在哪个目录下，如：which ls

  * grep指令和管道符号|

    grep过滤查找

    > 管道符号‘|’，表示将前一个命令的处理结果输出传递给后面的处理命令

    格式：grep [选项] [查找内容] [源文件]

    常用选项：-n:显示匹配行及行号

    -i： 忽略字母大小写

  * gzip/gunzip指令

    gzip用于压缩文件，gunzip用于解压文件

    格式：gzip [文件名]  （压缩文件，只能将文件压缩为*.gz文件）

    gunzip [文件名.gz]（解压缩文件）

  * zip/unzip指令

    zip用于压缩文件或者文件夹，unzip用于解压缩

    格式：zip [选项] xxx.zip [文件或目录]（压缩文件或目录，xxx.zip为指定压缩后的文件名）

    unzip [选项] xxxzip （解压文件）

    常用选项：-r : 递归压缩，即压缩目录时使用

    -d [目录] :解压到指定目录下 

  * tar 指令 ----打包指令，最后打包的文件是.tar.gz的文件

    格式：tar [选项] xxx.tar.gz [打包目录]

    选项：

    * -c:   产生.tar打包文件
    * -v：显示详细信息
    * -f:指定压缩后的文件名
    * -z:打包同时压缩
    * -x:解包.tar文件

***

### 组管理和权限管理

Linux中每个用户必须属于一个组，不能独立在于组外，咋Linux中每个文件有所有者，所在组，其他组的概念

1、所有者：即文件的当前拥有着或创建者

2、所在组：默认为所有者所在的组

3、其他组：除当前所在组外所有的其他组堆文件的权限

4、改变用户所咋的组

* 文件/目录所有者

  一般为文件的创建者

  * 查看文件的所有者

    指令:ls -ahl

  * 修改文件的所有者

    指令：chown [用户名] [文件名]

    > 使用touch [文件名] 创建文件

  * 修改文件所在组

    文件被创建时，所在组默认为创建者所在的组

    修改组指令：chgrp [组名] [文件名]

* 其他组

  除了文件所有者所在的组外，系统的其他用户都是文件的其他组

  * 改变用户所在组

    使用root的管理权限可以改变某个用户所在的组

    * usermod -g [新组名] [用户名]

    * usermod -d [目录名] [用户名]（改变该用户登陆的初始目录，用户需要有进入新目录的权限） 

      > 查看组名是否存在：cat /etc/group
      >
      > 或者精确查找：cat /etc/group | grep [组名]

* 权限地基本介绍

  使用ls -l 指令显示的第一列共有10位，其含义分别为：

  * 第0位确定文件类型(d,-,l,c,b)

    - -是普通文件

    * l 是链接，相当于Windows的快捷方式
    * d 是目录，相当于Windows的文件夹
    * c 是字符设备文件，如 鼠标，键盘
    * b 是块设备，比如硬盘

  * 第1-3位确定所有者拥有的权限 ----user
  * 第4-6位确定所属组拥有的权限 ---group
  * 第7-9位确定其他用户拥有该文件的权限 ---other

* rwx权限详解

  * rwx作用到文件

    * [r]	代表可读(read)：可以读取，查看
    * [w]   代表可写(write)：可以修改，但不代表可以删除文件，删除一个文件的前提条件是对该文件所在的目录有写权限，才能删除该问价

    * 代表可执行(execute)：可以倍执行

  * rwx作用到目录

    * [r]代表可读(read)：可以读取，ls命令查看目录内容

    * [w]代表可写(write)：可以修改，对目录内创建+删除+重命名

    * [x]代表可执行(execute)：可以进入该目录

      > 可以使用数字表示：r=4,w=2,x=1,因此，rwx=4+2+1=7
      >
      > 使用ls -l指令，在10位权限后跟的数字（也就是第11位），如果是文件代表硬连接数目，如果是目录代表子目录数

* 修改权限---chmod

  * +,-,=变更权限（+增加权限，-去除权限）

    u:所有者 g:所有组 o:其他人 a:所有人

    - chmod u=rwx,g=rx,o=x [文件/目录]
    - chmod o+w [文件/目录]
    - chmod a-x [文件/目录]

  * 使用数字来变更权限

    * chmod u=rwx,g=rx,o=x [文件名]

      相当于 chmod 751 [文件名/目录]

* 修改文件所有者--chown

  chown newowner [文件/目录] [改变所有者]

  chown newowner:newgroup [文件/目录] [改变所有者和所在组]

  -R 如果是目录，则使其下所有子女文件或目录递归生效

***

# Linux实操篇(下)

### 定时任务调度

* crond任务调度

  contab 进行定时任务调度

  * 概述：

    任务调度：是指系统在某个时间执行的特定的命令或程序

    任务调度分类：系统工作：有些重要的工作必须周而复始的执行，如病毒扫描；个别用户工作：个别瀛湖可能希望执行某些程序，比如对mysql数据库的备份

  * 格式：crontab [选项]

    * 常用选项：-e:编辑crontab定时任务
    * -l:查询crontab任务
    * -r:删除当前用户所有的crontab
    * service crond restart (重启任务调度 )

  * 入门案例：

    设置任务调度文件：/etc/crontab

    设置个人任务调度。执行crontab -e命令。

    接着输入任务到调度文件，比如：[* /1 * * * * * ls -l /etc/ > /tem/to.txt],意思是说每小时每分钟执行ls -l命令

    五个占位符的说明：

    * 第一个*：一小时中的第几分钟（0-59）
    * 第二个*：一天当中的第几个效使（0-23）
    * 第三个*：一个月当中的第几天（1-31）
    * 第四个*：一年当中的地几个月（1-12）
    * 第五个*：一周当中的星期几（0-7，0和7都代表周日）

  * 特殊符号的说明

    ![image-20220125093522681](C:\Users\小红君\AppData\Roaming\Typora\typora-user-images\image-20220125093522681.png)

  * 应用实例：

    * 案例1：每隔1分钟，就将当前的日期信息，追加到/tmp/mydate文件中

      步骤：[* /1 * * * * date >> /tmp/mydate]

    * 案例2：每隔1分钟，将当前日期和日历都追加到/home/mycal文件中

      步骤：

      * vim /home/my.sh 写入内容[date >> /home/mycal]和[cal >> /home/mycal]
      * 给 my.sh怎加执行权限，[chmod u+x /home/my.sh]
      * crontab -e 增加 [* /1 * * * * /home/my.sh]

* at定时任务

  * 基本介绍

    * at命令是一次性定时任务，at的守护进程atd会以后台模式运行，检查作业队列来运行

    * 默认情况下，atd守护进程每60秒检查作业队列，有作业时，会检车作业运行时间，如果时间与当前时间匹配，则运行此作业

    * at命令是一次性定时计划任务，执行完一个任务后不再执行此任务了

    * 在使用at 命令的时候，**一定要保证atd进程的启动**，可以使用相关指令来查看

      > 使用ps -ef 查看所有系统运行的进程
      >
      > 使用 ps -ef | grep atd 查看atd是否运行

  * 格式：at [选项] [时间]

    Ctrl + D 结束at命令的输入（按两次） 

    atrm [编号]  （删除编号的定时任务）

  * at命令选项

    ![image-20220125101458182](C:\Users\小红君\AppData\Roaming\Typora\typora-user-images\image-20220125101458182.png)

  * at时间定义

    ![image-20220125101605742](C:\Users\小红君\AppData\Roaming\Typora\typora-user-images\image-20220125101605742.png)

***

### Linux磁盘分区、挂载

* Linux分区

  * 原理介绍

    * Linux来说无论有几个分区，分给那一目录使用，它归根结底就只有一个根目录，一个独立且唯一的文件结构，Linux中每个分区都是用来组成整个文件系统的一部分

    * Linux采用了一种叫“载入”的处理方式，它的整个文件系统中包含了一整套的文件和目录，且将一个分区和一个目录联系起来。这时候要载入的一个分区将使得它的存储空间在下一个目录下获取。

    * 示意图

      ![image-20220125110105470](C:\Users\小红君\AppData\Roaming\Typora\typora-user-images\image-20220125110105470.png)

  * 硬盘说明

    * Linux硬盘分IDE硬盘和SCSI硬盘，目前基本都是SCSI硬盘

    * 对于IDE硬盘，驱动器标识符为“hdx~”,其中hd表面分区所在的设备类型，这里是指IDE硬盘。x为盘号（a为基本盘，b为基本从属盘，c为辅助主盘，d为辅助从属盘），~代表分区，前四个分区用数字1-4表示，他们是主分区或扩展分区，从5开始就是逻辑分区。比如：hda3表示第一个IDE硬盘上第三个主分区或扩展分区，hdb2表示第二个IDE硬盘上的第二给主分区或扩展分区

    * 对于SCSI则表示为“sdx~”，SCSI硬盘使用SD来表示分区所在的设备类型的，其余则和IDE硬盘的表示方法一样

      > 查看所有设备挂载情况
      >
      > 命令:lsblk  或者 lsblk -f

  * 案例:挂载一块磁盘

    * 如何添加一块硬盘:

      * 虚拟机添加硬盘

        虚拟机设置-->添加--->硬盘

      * 分区

        分区命令:fdisk /dev/sdb

        开始对/sdb   

        > m 显示命令列表
        >
        > p 显示磁盘分区 同 fdisk -l
        >
        > n 新增分区
        >
        > d 删除分区
        >
        > w 写入并退出

        说明:开始分区后输入n,新增分区,然后选择p ,分区类型为主分区.两次回车默认全部空间.最后输入w写入分区并退出,若不保存退出输入q

      * 格式化

        命令:mkfs -t ext4 /dev/sdb1

        ext4是文件类型

      * 挂载

        就是将一个分区和一个目录联系起来

        命令:mount [设备名称] [挂载目录]  (挂载)

        umount [设备名称/挂载目录]  (卸载/取消挂载)

        **注:用命令行执行的挂载.系统重启后会失效**

      * 设置可以自动挂载/永久挂载

        通过修改/etc/fstab实现挂载

        > /dev/sdb1        /newdisk    ext4      default   00

        添加完成后.执行 mount -a 即刻生效

* 磁盘情况查询

  * 查询系统整体磁盘使用情况

    格式:df -h

  * 查询指定目录的磁盘占用情况

    格式:du -h [/目录]  (默认为当前目录)

    > -s  指定目录占用大小汇总
    >
    > -h 带计量单位
    >
    > -a 含文件
    >
    > --max-depth=1  子目录深度
    >
    > -c 列出明细的同时,增加汇总值

* 磁盘情况--工作实用指令

  * 统计/opt文件夹下文件的个数

    > ls -l /opt | grep "^-" | wc -l
    >
    > grep支持正则表达式,""中为正则表达式,意思为:以'-'开头的文件,wc是字符统计的意思

  * 统计/opt文件夹下目录的个数

    > ls -l /opt | grep "^d" | wc -l

  * 统计/opt文件夹下文件的个数,包括子文件夹里面的

    > ls -lR /opt | grep "^-" | wc -l

  * 统计/opt文件夹下目录的个数,包括子文件夹里面的

    > ls -lR /opt | grep "^d" | wc -l

  * 以树状图显示目录结构

    > tree [目录名]
    >
    > 如果没有tree指令,使用yum install tree指令安装tree指令

***

### Linux网络配置

* Linux 网络配置原原理图

![](C:\Users\小红君\Desktop\Linux韩顺平\NAT网络配置.jpg)

* 查看网络IP和网关

  * 查看虚拟网络编辑器和修改IP地址

    虚拟机:编辑---->虚拟网络编辑器

  * 查看IP地址

    > Windows下:ipconfig
    >
    > linux :ifconfig

* linux网络环境配置

  * 第一种方法(自动获取)

    登陆后,通过界面的来设置自动获取ip,特点:linux启动后会自动获取IP ,缺点是每次自动获取的ip地址可能不一样

    > 设置-->网络

  * 第二种方法(指定IP)

    直接修改 配置文件来指定IP,并可以链接到外网(程序员推荐)

    > 编辑 vim /etc/sysconfig/network-scripts/ifcfg-ens33

    要求:将IP地址配置的静态的,比如:ip地址为192.168.200.130

    ifcfg-ens33文件说明

    > DEVICE=eth0 (接口名(设备,网卡))
    >
    > HWADDR=00:0C:2x:6x:0x:xx  (MAC地址)
    >
    > TYPE=Ethernet   (网络类型(通常是Ethenet))
    >
    > UUID=926a-57ba-92c6-4231-bacb-f27e   ( 随机ID)
    >
    > #系统启动的时候网络接口是否有效(yes/no)
    >
    > **ONBOOT=yes**
    >
    > #IP的配置方法[none|static|bootp|dhcp] (引导时不使用协议|静态分配IP|BOOTP协议|DHCP协议)
    >
    > **BOOTPROTO=static**  
    >
    > #IP地址
    >
    > **IPADDR=192.168.145.128**
    >
    > #网关
    >
    > **GATEWAY=192.168.145.2**
    >
    > #域名解析器
    >
    > **DNS1=192.168.145.2**

    重启网络服务或者重启系统生效

    service  network   restart 

    或者

    reboot 

* 设置主机名和hosts映射

  * 设置主机名

    * 为了方便记忆,可以给Linux系统设置主机名,也可以更具需要修改主机名
    * 指令hostname:查看主机名
    * 修改后,重启生效

  * 设置hosts映射

    * windows系统下

      C:\Windows\System32\drivers\etc\hosts 文件指定即可

    * linux系统

      在/etc/hosts 文件 指定

  * 主机名解析过程分析(Hosts,DNS)

    * ​	hosts是什么

      一个文本文件,用来记录IP和Hostname(主机名)的映射关系

    * DNS

      域名系统,互联网上作为域名和地址相互映射的一个分布式数据库

      > windows系统下:
      >
      > ipconfig /displaydns    (DNS 域名解析 缓存)
      >
      > IP从fig /flushdns    (手动清理DNS缓存)

***

### 进程管理⭐

* 基本介绍

  进程拥有两种存在方式：前台和后台。

* 显示系统执行的进程

  ps命令，可以查看哪些葬在执行的进程以及状况

  > USER :进程执行的用户
  >
  > PID :进程识别号
  >
  > PPID :父进程ID,0表示无父进程
  >
  > %CPU: 占用CPU百分百
  >
  > %MEM :占用物理内存百分百
  >
  > VSZ : 占用虚拟内存的大小(KB)
  >
  > RSS:占用物理内存的大小 (KB)
  >
  > STAT :当前运行状态,s代表sleep休眠,r代表run运行
  >
  > TTY  :终端机号
  >
  > START:开始时间
  >
  > TIME :  消耗CPU时间
  >
  > COMMOND: 正在执行的命令或进程名

  ps -a  :显示当前终端的所有进程信息

  ps -u :以用户名的格式显示进程信息

  ps -x :显示后台进程运行的参数

  > 一般会选择将三个命令组合使用:ps -aux | more
  >
  > 如果查看具体的某个进程的信息,使用:ps -aux | grep xxx

  ps -ef:是以全格式显示当前所有进程

  -e: 显示所有进程;-f:全格式

* 终止进程

  格式: kill [选项] [进程号] (通过进程号杀死进程)

  killall [进程名称]  (通过进程名称杀死进程,支持通配符,常用于系统因负载过大而变得很慢时)

  选项:-9  :表示强迫进程立即停止

* 查看进程树pstree

  格式:pstree [选项] (可以更加直观的来查看进行信息)

  选项: -p : 显示进程的PID

  -u :显示进程的所属用户

* **服务管理(service)**

  服务的本质就是进程,但其是后台运行,通常都会监听某个端口,等待其他的程序请求,因此又可以程为守护进程

  * service 管理指令

    * service [服务名] [start|stop|restart|reload|status]
    * CentOS 7 之后很多服务叜使用service,而是使用sysyemctl
    * service 指令管理的服务在 /etc/init.d 查看 

  * 查看服务名

    使用setup -> 系统服务  就可以看到全部

    /etc/init.d 看到service指令管理的服务

  * 服务的运行级别(runlevel)

    Linux拥有7种运行级别,最常用的是3和5

    ![image-20220207101928115](C:\Users\小红君\AppData\Roaming\Typora\typora-user-images\image-20220207101928115.png)

  * chkconfig指令

    通过chkconfig命令可以给服务的各个运行级别设置自启动/关闭

    chkconfig指令管理的服务在 /etc/init.d 查看

    格式:chkconfig --list | grep xxx  (查看服务)

    chkconfig [服务名] --list

    chkconfig --level 5 [服务名] on/off

    > chkconfig重新设置服务自启动或者关闭,需要重启生效

  * **systemctl管理指令**

    格式:systemctl [start|stop|restart|status] [服务名]

    systemctl指令的服务在 /user/lib/systemd/system 查看

    * 设置自启动状态

      * systemctl list-unit-filed | grep [服务名]  (产看服务开机启动状态,grep进行过滤)

      * systemctl enable [服务名]  (设置服务开机启动)

      * systemctl disable [服务名]  (关闭服务关机启动)

      * systemctl is-enabled [服务名] (产需某个服务是否是开机自启动) 

        > 防火墙服务firewall.service
        >
        > 在cmd窗口使用telnet [IP地址] 命令检测是否开启服务.开启telnet命令:控制面板->程序->打开或关闭Windows功能->telnet客户端

  * 打开/关闭指定端口

    在实际生产环境中,往往需要打开防火墙,那么外部的请求数据包就不能跟服务器监听端口通信,这时,就需要打开指定的端口.

    firewall指令

    打开端口:firewall-cmd --permanent --add-port=[端口号/协议]

    关闭端口:firewall-cmd --permanent --remove-port=[端口号/协议]

    重新载入才能生效:firewall-cmd --reload

    查询端口是否开放:firewall-cmd --query-port=[端口/协议]

  * 动态监控进程

    top 在执行一段时间后可以更新正在运行的进程

    格式:top [选项]

    选项:-d [秒数] :指定top命令每隔几秒更新,默认时间3秒

    -i : 使得top不下十任何闲置或者僵死的进程

    -p : 通过指定监控进程ID来监控某个进程状态

    top命令具有交互功能,其操作说明

    > P :以CPU使用率排序,默认就是此项
    >
    > M:以内存的使用率排序
    >
    > N:以PID排序
    >
    > u:输入需要监控的用户
    >
    > k:输入要结束的进程ID号
    >
    > q:退出top

  * 监控网络状态

    * 查看网络情况netstat

      格式:netstat [选项]

      选项:-an :按一定的顺序排列输出

      -p :显示哪个进程在调用

      

***

### RPM与YUM

* RPM包

  rpm用于互联网下载包的打包机安装工具,它包含在某些Linux发布版中.它生成具有.RPM扩展名的文件.    RPM是RedHat Package Manage的缩写,类似于Windows中的setup.exe

  * rpm包的简单查询指令

    查询已安装的rpm列表  :  rpm -qa | grep xxx 

  * rpm包名基本格式

    一个rpm包名:firefox-60.2.2-1.el7.centos.x86_64

    名称:Firefox

    版本号:60.2.2-1

    适用操作系统:el7.centos.x86_64,表示centos7.x的64位操作系统,如果是i686,i386表示32位系统,noarch表示通用

  * rpm包的其他查询指令

    > rpm -qa :查询所安装的所有rpm包
    >
    > rpm -qa | more
    >
    > rpm -qa | grep xxx
    >
    > rpm -q [软件包名]  :查询软件包是否安装
    >
    > rpm -qi [软件包名] :查询软件包信息
    >
    > rpm -ql [软件包名] :查询软件包中的文件(可用来查询安装路劲)
    >
    > rpm -qf [文件全路径名] :  查询文件所属的软件包

  * rpm包的卸载

    格式:rpm -e [rpm包名称]

    >如果其他软件包依赖于要卸载的软件包,卸载是会产生错误信息,可以选择增加参数 --nodeps  ,可以强制删除.但是不推荐这么做,可能导致依赖程序无法运行

  * 安装rpm包

    格式:rpm -ivh [rpm包全路径名称]

    参数:-i :install安装

    -v :verbose提示

    -h :hash进度条

* YUM

  yum是一个shell前端软件包管理器,基于rpm包管理,能够从指定的服务器自动下载rpm包并且安装,可以自动处理依赖性管理,并且一次安装所有软件包

  * 基本指令

    查询yum服务器是否有需要安装的软件

    > yum list | grep [软件列表]

    安装指定的yum包

    > yum install xxx

***

# JavaEE定制篇

### 搭建JavaEE环境

* 安装JDK

  安装步骤：

  > 1.mkdir /opt/jdk
  >
  > 2.通过xftp上传到 /opt/jdk下
  >
  > 3.cd /opt/jdk
  >
  > 4.解压 tar -zxvf jdk-8u261-linux-x64.tar.gz
  >
  > 5.mkdir /user/local/java
  >
  > 6.mv /opt/jdk/jdk1.2.0_261 /usr/local/java
  >
  > 7.配置环境变量的配置文件：vim /etc/profile
  >
  > 8.export JAVA_HOME=/usr/local/java/jdk1.8.0_261
  >
  > 9.export PATH=$JAVA_HOME/bin:$PATH
  >
  > 10.source /etc/profile  (让文件生效)

  测试是否安装成功

* 安装tomcat

  * 安装步骤

    > * 上传安装文件，并解压缩到 /opt/tomcat
    > * 进入解压目录/bin，启动tomcat  ./startup.sh
    > * 开放端口 8080  (放入防火墙打开端口中)

  * 测试是否安装成功：

    在Windows，Linux下访问 http:[linuxip]:8080

* 安装IDEA2020

  步骤：

  > 1.下载 https://www.jetbrains.com/idea/download/#section=linux
  >
  > 2.解压缩到 /opt/idea
  >
  > 3.启动idea,在bin目录下 ：./idea.sh   配置JDK
  >
  > 4.测试

  注意：不能使用远程登陆的方式运行idea,需要到原系统界面去运行

* 安装Mysql5.7

  步骤：

  > 1.mkdir /opt/mysql，进入文件夹
  >
  > 2.运行 wget http://[mysql的安装包地址]，下载mysql
  >
  > 注1：centos7.6自带一个数据库mariadb，会与MySQL冲突，需要先删除
  >
  > 注2：wget指令会通过互联网去自动搜索下载路径中的文件
  >
  > 3.运行 tar -xvf [mysql包名称]
  >
  > 4.运行 rpm -qa | grep mari ,查询mariadb相关安装包
  >
  > 5.rpm -e --nodeps mariadb-libs ，卸载
  >
  > 6.开始安装MySQL：按顺序执行！

  > * rpm -ivh mysql-community-common-5.7.26-1.el.x86_64.rpm
  > * rpm -ivh mysql-community-libs-5.7.26-1.el.x86_64.rpm
  > * rpm -ivh mysql-community-client-5.7.26-1.el.x86_64.rpm
  > * rpm -ivh mysql-community-server-5.7.26-1.el.x86_64.rpm

  > 7.运行 systemctl start mysqld.service ，启动MySQL
  >
  > 8.设置root用户密码
  >
  > MySQL自动给root用户设置随机密码，运行grep "passward" /var/log/mysqld.log  可产看当前密码
  >
  > 9.mysql -u root -p，用root用户登陆，提示输入密码可以用上述查到的，可以成功登陆进mysql命令行
  >
  > 10.设置root密码，set global validate_password_policy=0;提示密码设置策略（validate_password_policy默认值1；0表示弱，1表示中等，2表示强）
  >
  > 11.set password for 'root'@'localhost' =password('[新密码]');
  >
  > 12.flush privileges;使得密码生效

***

# 大数据定制篇(shell)

### shell编程

* shell简介

  shell是一个命令解释器，它为用户提供了一个向Linux内核发送请求以便运行程序的界面系统级程序，用户可以用shell来启动、挂起、停止甚至编写一些程序。

  ![image-20220207181652695](C:\Users\小红君\AppData\Roaming\Typora\typora-user-images\image-20220207181652695.png)

* shell脚本的执行方式

  * 格式要求：

    * 脚本以#！/bin/bash  开头
    * 脚本需要有可执行权限

  * 实例：创建一个shell脚本，输出Hello world！

    * 脚本常用的执行方式：

      * 输入脚本的绝对路径或相对路径

        首先要赋予helloworld.sh 脚本的 ‘+x’ 权限，在执行脚本

      * sh [脚本名称]

        不用赋予 ‘+x’ 权限，直接执行即可

* shell的变量

  * shell变量的介绍

    * Linux shell中的变量分为系统变量和用户自定义变量
    * 系统变量：￥HOME、$PWD、$SHELL、$USER等等
    * 显示当前shell中的所有变量：set

  * shell变量的定义

    * 定义变量：变量名=值

    * 撤销变量：unset [变量名]

    * 声明静态变量：readonly [变量名]  （不能unset静态变量）

      > 使用#符号注释，多行注释需要使用   :<<!  内容   !  (最好独立成行)
      >
      > 输出变量需要在变量名前加$：如$A

    * 定义规则：

      > 变量名称可以由字母，数字和下划线组成，但是不能以数字开头
      >
      > 等号两侧不能有空格
      >
      > 变量名称一般习惯大写

    * 将命令的返回值赋值给变量

      > A='data' 反引号，运行里面的命令，并版结果返回给变量A
      >
      > A=$(data)  等价于反引号

  * 设置环境变量

    * 格式：
      * export [变量名]=[变量值]  （将shell变量输出为环境变量）
      * source [配置文件路径]  （让修改后的配置文件立即生效）
      * echo $[变量名]  （查询环境变量的值）

  * 位置参数变量

    当我们执行一个shell脚本时，如果希望获取到命令行的参数信息，就可以使用到位置参数变量，比如：./myshell.sh 100 200,j就是一个执行shell的命令，可以在myshell脚本中获取到参数信息。

    * 格式：
      * $n （n为数字，$0代表命令本身，$1-$9代表第一到第九个参数，十以上的参数需要用大括号包含，如${10}）
      * $* （这个变量代表命令行中的所有的参数，$*把所有的参数看成一个整体）
      * $@ （这个变量代表命令行中的所有参数，不过$@把每个参数区分对待）
      * $# （这个变量代表命令行中所有参数的个数）

    ```sh
    #!/bin/bash
    #类似于C语言函数中的参数列表，传参
    echo $0 $1 $2
    echo $*
    echo $@
    echo $#
    
    #调用positon.sh
    sh position.sh 100 200
    #结果
    position.sh 100 200
    100 200
    100 200
    2
    ```

  * 预定义变量

    shell设计者事前已经定义好的变量，可以直接在shell脚本中使用

    * 格式：$$ （当前进程的进程号）

      $! （后台运行的最后一个进程的进程号）

      $? （最后一次执行的命令的返回状态。如果这个变量的值为0，挣嘛上一个命令正确执行；如果这个变量的值非0（具体哪个数，由命令自己来决定），则证明上一个命令执行不正确了。）

      ```sh
      #!/bin/bash
      echo "当前执行的进程ID=$$"
      #以后台的方式运行一个脚本，并获取它的进程号（后面需要带一个&取地址）
      /root/shcode/var.sh &
      echo "最后一个后台方式运行的进程id=$!"
      echo "执行的结果=$?"
      ```

  * 运算符

    * 格式：

      * “$((运算式))”或“$[运算式]”或“expr m + n”   (注意expr运算符之间要有空格,如果要将结果赋值给某个变量，使用 反引号括起来)

      * expr m - n

        ```sh
        #!/bin/bash
        # expr \*,/,%   乘，除。取余，乘号要转义
        #案例一 计算（2+3）*4
        RES1=$(((2+3)*4))
        RES2=$[(2+3)*4]
        TEMP=`expr 2 + 3` #使用``括起来
        RES3=`expr $TEMP \* 4`
        echo $RES1 $RES2 $RES3
        #案例二  求出命令行的两个参数的和
        SUM=$[$1+$2]
        echo "sum=$SUM"
        ```

  * 条件判断

    格式：[ condition ] （注意condition前后都有空格）

    非空返回treu，可使用$?验证(0为true,>1为false)

    * 判断条件

      > 常用判断条件
      >
      > １.＝　字符串比较
      >
      > ２.两个整数的比较
      >
      > -lt 小于
      >
      > -le 小于等于
      >
      > -eq 等于
      >
      > -gt 大于
      >
      > -ge 大于等于
      >
      > -ne 不等于
      >
      > 3.按照文件权限进行比较
      >
      > -r 读
      >
      > -w 写
      >
      > -x 执行
      >
      > 4.按照文件类型判断
      >
      > -f 文件存在且是一个常规文件
      >
      > -e 文件存在
      >
      > -d 文件存在且是一个目录

    ```shell
    #!/bin/bash
    #1.ok 是否等于 ok
    if [ "ok"="ok" ]
    then
    	echo "echo"
    fi
    #2.23是否大于等于22
    if [ 23 -ge 22 ]
    then
    	echo "大于"
    fi
    #3./root/shcode/aaa.txt 目录中的文件是否存在
    if [ -f /root/shcode/aaa.txt ]
    then
    	echo "存在"
    fi
    #4.特殊案例
    if [  ]  #这里[  ]中condition为空，结果flase，注意不能写成[],中间是三个空格
    then
    	echo "flase" #永远不会被执行
    fi
    ```

  * 流程控制

    * if语句

      格式：

      ```shell
      #格式1
      if [ condition ]
      then 
      	#代码段
      fi
      #格式2
      if [ condition1 ]
      then 
      	#代码段1
      elif [ condition2 ]
      then
      	#代码段2
      fi
      ```

      注意：务必注意[ condition ]condition与[]之间的空格

      ```shell
      #！/bin/bash
      #案例：输入一个参数，如果大于等于60，输出：及格，否则输出：不及格
      if [ $1 -ge 60 ]
      then
      	echo "及格"
      elif [ $1 -lt 60 ]
      then
      	echo "不及格"
      fi
      ```

    * case语句

      格式：

      ```shell
      case $变量名 in
      “value1”)
      #代码1：如果变量的值等于value1，执行此段代码
      ;;
      "value2")
      #代码2：如果变量的值等于value2，执行此段代码
      ;;
      ......
      *)
      #如果以上都不满足，执行这段代码
      ;;
      esac
      ```

      ```shell
      #!/bin/bash
      #案例：当命令行参数是1时，输出：周一，2输出：周二，其他输出：other
      case $1 in
      "1")
      echo "周一"
      ;;
      "2")
      echo "周二"
      ;;
      *)
      echo "other"
      ;;
      esac
      ```

    * for循环

      ```shell
      #格式1
      for 变量 in 值1 值2 值3 ...
      do
      #代码段
      done
      
      #格式二
      for ((初始值;循环控制条件;变量变化))
      do
      #代码段
      done
      ```

      ```shell
      #!/bin/bash
      #案例1 打印命令行输入的参数
      for i in "$*"
      do
      	echo "num=$i" 
      done
      ```

      > **注意**：这里体现了$*和$@的不同
      >
      > 这里调用输入参数100 200 ，打印结果为：num=100 200;是因为使用$* 取参数，会将参数列表作为一个整体，如果换成$@，打印结果为：num=100  num=200

      ```shell
      #!/bin/bash
      #案例2 输出从1加到100的值
      SUM=0
      for ((i=1;i<=100;i++))
      do
      	SUM=$[$SUM+$i]
      done
      echo $SUM
      ```

    * while循环

      ```shell
      while [ condition ]
      do
      #代码段
      done
      ```

      ```shell
      #!/bin/bash
      #案例：从命令行输入一个数n，计算输出1加到n的和
      SUM=0
      i=0
      while [ $i -le $1 ]   #不能写成 i<=$1
      do
      	SUM=$[$SUM+$i]
      	i=$[$i+1]  #不能写成i++
      done
      echo $SUM
      ```

    * read读取控制台输入

      格式：read [选项] [参数]

      选项：-p: 指定读取值时候的提示符

      -t : 指定读取值时候等待的时间(秒)，如果没有在指定的时间内输入，就不再等待

      参数：变量（指定读取值的变量名）

      ```shell
      #！/bin/bash
      #案例1：读取控制台输入一个NUM1值
      read -p "输入NUM1=" NUM1
      echo $NUM1
      #案例2:读取控制台输入一个NUM2值，在10秒内输入
      read -t 10 -p "输入NUM2=" NUM2
      echo $NUM2
      ```

      

  * 系统函数

    shell编程也拥有系统函数，也可以自定义函数。介绍两个系统函数

    * basename函数

      返回完整路径最后 / 的部分，常用于获取文件名

      格式：basename [pathname] [suffix]

      basename [string] [suffix]  (basename会删除所有的前缀包括最后的一个‘/'字符，然后将字符串显示出来)

      选项:suffix为后缀，如果suffix倍指定了，basename会将pathname或string中的suffix去掉

      ```shell
      #！/bin/bash
      #案例1：返回 /home/aaa/test.txt 的test.txt部分 
      basename /home/aaa/test.txt 	 #test.txt
      basename /home/aaa/test.txt .txt #test
      ```

    * dirname函数

      返回完整路径最后 / 的前面的部分，常用于返回路径部分

      格式：dirname [文件绝对路径]  （从给定的包含绝对路径的文件名中去除文件名（非目录部分），然后反hi剩下的路径（目录部分））

      ```shell
      #！/bin/bash
      #案例：返回 /home/aaa/test.txt的/home/aaa
      dirname /home/aaa/test.txt
      ```

  * 自定义函数

    ```shell
    function [funname]()
    {
    	Action;  #函数功能代码段
    	return int; #返回值，如果没有就不写
    }
    #调用函数
    funname 值
    ```

    ```shell
    #！/bin/bash
    #案例：计算输入的两个参数的和，getSum
    function getSum(){
    	SUM=$[$num1+$num2]
    	echo $SUM
    }
    read -p "num1=" num1
    read -p "num2=" num2
    getSum $num1 $num2
    ```

* shell 编程综合案例

  * 需求分析

    > * 每天凌晨2：30备份数据库 testDB到 /data/backup/db
    > * 备份开始和备份结束能够给出相应的提示信息
    > * 备份后的文件要求以备份时间为文件名，并且打包成.tat.gz的形式
    > * 在备份的同时检查是否有10天前备份的数据库文件，如果有就将其删除

  ```shell
  #!/bin/bash
  #备份目录
  BACKUP=/data/backup/db
  #当前时间
  DATETIME=$(date +%Y-%m-%d_%H%M%S)
  echo $DATETIME  #测试
  #数据库地址
  HOST=localhost
  #数据库用户名
  DB＿USER=root
  #数据库密码
  DB_PW=root
  #备份数据库名
  DATABASE=test
  
  #创建备份目录
  [ ! -d "${BACKUP}/${DATETIME}" ] && mkdir -p "${BACKUP}/${DATETIME}"
  
  #备份数据库
  mysqldump -u${DB_USER} -p${DB_PW} --host=${HOST} -q -R --databases ${DATABASE} | gzip > ${BACKUP}/${DATETIME}/$DATETIME.sql.gz
  
  #将文件处理成 tar.gz
  cd ${BACKUP}
  tar -zcvf $DATETIME.tar.gz ${DATETIME}
  #删除对应的备份目录
  rm -rf ${BACKUP}/${DATETIME}
  
  #删除10天前的备份文件
  find ${BACKUP} -atime+10 -name "*.tar.gz" -exec rm -rf {} \;
  echo "backup success"
  ```

  使用crontab执行定时任务：crontab -e

  ```shell
  30 2 * * * /usr/sbin/mysql_db_backup.sh
  ```

  