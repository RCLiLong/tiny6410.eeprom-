# tiny6410.eeprom-
友善之臂tiny6410使用qt2.2.0实现eeprom内存看看器

24cXX.cpp	提供eeprom打开、关闭、写、读，具体名称可查看24cXX.h
main_form.cpp	主窗函数，实现具体的读、写、查看上一页，下一页功能。
main.cpp		主函数，只有四行它的实现很简单，宏展开后会是一个 main 函数，然后创建QPEApplication 对象 和  TMainForm主窗口对象，最后显示主窗口并执行 QApplication::exec()进入事件循环
eer		可执行文件，导入/opt/Qtopia/bin 中使用
eer.desktop	桌面文件，导入/opt/Qtopia/apps/Applications中使用
main_form_base.ui	qt的ui文件
buildarm.sh Makefile.target	提供在文件目录./buildarm.sh一键编译功能（如果没有权限，请chmod 777 buildarm.sh）
