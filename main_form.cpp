#include "main_form.h"
#include <qlineedit.h>

#include <stdio.h>
#include <fcntl.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "24cXX.h"

using namespace std;

#define usage_if(a) do { do_usage_if( a , __LINE__); } while(0);
void do_usage_if(int b, int line)
{
	const static char *eeprog_usage = 
		"I2C-24C08(256 bytes) Read/Write Program, ONLY FOR TEST!\n"
		"Base on 'eeprog' by Stefano Barbato (http://codesink.org/eeprog.html)\n"
		"FriendlyARM Computer Tech. 2009\n";
	if(!b)
		return;
	fprintf(stderr, "%s\n[line %d]\n", eeprog_usage, line);
	exit(1);
}


#define die_if(a, msg) do { do_die_if( a , msg, __LINE__); } while(0);
void do_die_if(int b, char* msg, int line)
{
	if(!b)
		return;
	fprintf(stderr, "Error at line %d: %s\n", line, msg);
	fprintf(stderr, "	sysmsg: %s\n", strerror(errno));
	exit(1);
}

int TMainForm::  read_from_eeprom(struct eeprom *e, int addr)
{
	int ch, i;
	int addr2=addr;
	for(i = 0; i < 16; ++i, ++addr)
	{
		die_if((ch = eeprom_read_byte(e, addr)) < 0, "read error");
		switch(i)
		{
			case(0):L_0l->setText( QString::number(ch,16) );T_0->setText( QString::number(addr2+i) );break;
			case(1):L_1l->setText( QString::number(ch,16) );T_1->setText( QString::number(addr2+i) );break;
			case(2):L_2l->setText( QString::number(ch,16) );T_2->setText( QString::number(addr2+i) );break;
			case(3):L_3l->setText( QString::number(ch,16) );T_3->setText( QString::number(addr2+i) );break;
			case(4):L_4l->setText( QString::number(ch,16) );T_4->setText( QString::number(addr2+i) );break;
			case(5):L_5l->setText( QString::number(ch,16) );T_5->setText( QString::number(addr2+i) );break;
			case(6):L_6l->setText( QString::number(ch,16) );T_6->setText( QString::number(addr2+i) );break;
			case(7):L_7l->setText( QString::number(ch,16) );T_7->setText( QString::number(addr2+i) );break;
			case(8):L_8l->setText( QString::number(ch,16) );T_8->setText( QString::number(addr2+i) );break;
			case(9):L_9l->setText( QString::number(ch,16) );T_9->setText( QString::number(addr2+i) );break;
			case(10):L_10l->setText( QString::number(ch,16) );T_10->setText( QString::number(addr2+i) );break;
			case(11):L_11l->setText( QString::number(ch,16) );T_11->setText( QString::number(addr2+i) );break;
			case(12):L_12l->setText( QString::number(ch,16) );T_12->setText( QString::number(addr2+i) );break;
			case(13):L_13l->setText( QString::number(ch,16) );T_13->setText( QString::number(addr2+i) );break;
			case(14):L_14l->setText( QString::number(ch,16) );T_14->setText( QString::number(addr2+i) );break;
			case(15):L_15l->setText( QString::number(ch,16) );T_15->setText( QString::number(addr2+i) );break;
			default : break;
		}
	}
	return 0;
}

static int write_to_eeprom(struct eeprom *e, int addr,int data)
{
	
	eeprom_write_byte(e, addr, data);
	return 0;
}



void TMainForm:: shang_slot()
{
	struct eeprom e;
        die_if(eeprom_open("/dev/i2c/0", 0x50, EEPROM_TYPE_8BIT_ADDR, &e) < 0,
                        "unable to open eeprom device file "
                        "(check that the file exists and that it's readable)");

        if(L_r->text().isEmpty())
        {
                return ;
        }
         bool ok = false;
     int addr = L_r->text().toInt(&ok);
     if (!ok) {
        L_r->setText("");
        return ;
     }
	addr-=16;
        read_from_eeprom(&e, addr);
	L_r->setText( QString::number(addr) );

} 
void TMainForm:: xia_slot()
{
	struct eeprom e;
        die_if(eeprom_open("/dev/i2c/0", 0x50, EEPROM_TYPE_8BIT_ADDR, &e) < 0,
                        "unable to open eeprom device file "
                        "(check that the file exists and that it's readable)");

        if(L_r->text().isEmpty())
        {
                return ;
        }
         bool ok = false;
     int addr = L_r->text().toInt(&ok);
     if (!ok) {
        L_r->setText("");
        return ;
     }
	addr+=16;
        read_from_eeprom(&e, addr);
	L_r->setText( QString::number(addr) );

}
void TMainForm:: read_slot()
{
  	struct eeprom e;
        die_if(eeprom_open("/dev/i2c/0", 0x50, EEPROM_TYPE_8BIT_ADDR, &e) < 0,
                        "unable to open eeprom device file "
                        "(check that the file exists and that it's readable)");

	if(L_r->text().isEmpty())
	{
		return ;
	}
	 bool ok = false;
     int addr = L_r->text().toInt(&ok);
     if (!ok) {
        L_r->setText("");
        return ;
     }
	read_from_eeprom(&e, addr);

}
void TMainForm:: write_slot()
{
    struct eeprom e;
	die_if(eeprom_open("/dev/i2c/0", 0x50, EEPROM_TYPE_8BIT_ADDR, &e) < 0, 
			"unable to open eeprom device file "
			"(check that the file exists and that it's readable)");

    if (L_addr->text().isEmpty() || L_data->text().isEmpty()) { 
        return ; 
     }
     bool ok = false; 
     int addr = L_addr->text().toInt(&ok); 
     if (!ok) { 
        L_addr->setText(""); 
        return ; 
     } 
     ok = false; 
     int data = L_data->text().toInt(&ok); 
     if (!ok) { 
        L_data->setText(""); 
        return ; 
     } 
     write_to_eeprom(&e, addr, data);
    if(data == eeprom_read_byte(&e, addr))
    {
        L_addr->setText( "succeed" ); 
        L_data->setText( "succeed" ); 
        eeprom_close(&e);
    }
}
