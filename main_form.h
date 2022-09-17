#if !defined (__MAIN_FORM_H__) 
#define __MAIN_FORM_H__
 
#include "main_form_base.h" 
#include <qsocketnotifier.h>

#include <qlabel.h>
#include <qpushbutton.h>
#include <qstring.h>
#include <stdlib.h>
#include <qlineedit.h> 

class TMainForm: public TMainFormBase { 
     Q_OBJECT
 
public: 
     TMainForm(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel) : TMainFormBase(parent,name,f) {}  
     virtual ~TMainForm() {} 
public slots: 
     int read_from_eeprom(struct eeprom *e, int addr);
     void shang_slot(); 
     void xia_slot();
     void read_slot();
     void write_slot();
}; 
#endif 
