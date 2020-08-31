#include "blisytv.h"
#include "ui_blisytv.h"
#include <cmath>
#include <iostream>
#include <QFile>

//defining global ints
int targetf;
int seedlag;
long double secrettarget;
int secrettv;
int delayboxvalue;
long double introtimerms;
int abratimer;
int secretflowtarget;
int newframe;
int secretframehit;
int secretintrotimer;
int totaloutput;


//defining global long doubles(I use longdoubles with things for decimals, everything eventually ends as an int, but the rounding is better whenever two longdoubles multiply vs eachother)
long double frameRate;
long double seedlagms;

//defining global qstrings
QString console;
QString gameversion;
QString method;
QString abratimerms;
QString pretimergame;

blisytv::blisytv(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::blisytv)
{
    ui->setupUi(this);


}

// This is a function to make the R/S/E ID parameter change to -75 instead of -249 automatically.
void blisytv::Methodbox(){
method = ui->methodbox->currentText();
gameversion = ui->versionBox->currentText();

if (method == "Stationary (Method 1/2/4)"){
    ui->delaybox->setEnabled(true);
    ui->delaybox->setValue(-20);
}   else if (method == "Sweet Scent (Outside)"){
    ui->delaybox->setEnabled(false);
    ui->delaybox->setValue(-261);
}   else if (method == "Sweet Scent (Cave)"){
    ui->delaybox->setEnabled(false);
    ui->delaybox->setValue(-268);
}   else if (method == "SID" && gameversion =="RS"){
     ui->delaybox->setEnabled(true);
    ui->delaybox->setValue(-75);


}else if (method == "SID" && gameversion == "Emerald"){
    ui->delaybox->setEnabled(true);
    ui->delaybox->setValue(-50);

}
else if (method == "SID" && (gameversion == "FireRed 1.0" || "FireRed 1.1" || "LeafGreen")){
    ui->delaybox->setEnabled(true);
   ui->delaybox->setValue(-249);
}
else{
    ui->delaybox->setValue(delayboxvalue);
}

}
//This is a function to change the value in the introtimer box. 35000 is the standard for FRLG on NDS. 30833 is an equivalent of that for GBA. 5000 is the norm for RSE.
void blisytv::Pretimer()
{
    gameversion = ui->versionBox->currentText();
    pretimergame = ui->consoleBox->currentText();


if(pretimergame == "NDS" && gameversion == "FireRed 1.0"){

    ui->introtimer->setValue(35000);
}
else if(pretimergame == "NDS" && gameversion == "FireRed 1.1"){

    ui->introtimer->setValue(35000);
}
else if(pretimergame == "NDS" && gameversion == "LeafGreen"){

    ui->introtimer->setValue(35000);
}
else if(pretimergame == "NDS" && gameversion == "RS"){

    ui->introtimer->setValue(5000);
}else if(pretimergame == "NDS" && gameversion == "Emerald"){

    ui->introtimer->setValue(5000);
}else if (pretimergame == "GBA" && gameversion == "FireRed 1.0"){

    ui->introtimer->setValue(30833);

}else if (pretimergame == "GBA" && gameversion == "FireRed 1.1"){

    ui->introtimer->setValue(30833);

}else if (pretimergame == "GBA" && gameversion == "LeafGreen"){

    ui->introtimer->setValue(30833);

}else if (pretimergame == "GBA" && gameversion == "RS"){

    ui->introtimer->setValue(5000);

}else if (pretimergame == "GBA" && gameversion == "Emerald"){

    ui->introtimer->setValue(5000);

}else if (pretimergame == "3DS" && gameversion == "SM"){

    ui->introtimer->setValue(3500);
    ui->delaybox->setValue(0);


}else if (pretimergame == "3DS" && gameversion == "USUM"){

    ui->introtimer->setValue(2500);
     ui->delaybox->setValue(0);
}


else{
    ui->introtimer->setValue(ui->introtimer->value());

}

}


void blisytv::Settings()
{
console = ui->consoleBox->currentText();
if (console == "NDS"){
    frameRate = 59.6555;

}else if(console == "GBA"){
    frameRate = 59.7275;
}else{
    frameRate = 60.0000;
}

gameversion = ui->versionBox->currentText();

if (gameversion == "FireRed 1.0"){
    seedlag = 121;
   } else if (gameversion == "FireRed 1.1"){
    seedlag = 120;
} else if(gameversion == "LeafGreen"){
    seedlag = 114;
}
    else if(gameversion == "RS" || "Emerald" || "SM" || "USUM"){
        seedlag = 0;


}



//this takes the valuye from abratimers checkbox, converts it to ms after subtracting 20 and accounting for seedlag, then adds it to the introtimer
abratimer = (1 / frameRate * 1000 ) * (ui->abraframe->value() - 20 + seedlag) + ui->introtimer->value();
abratimerms = QString::number(abratimer);

seedlagms = 1 / frameRate * 1000 * seedlag;
introtimerms = ui->introtimer->value() + seedlagms;

delayboxvalue = ui->delaybox->value();



}

//this changes the intro timer based on console. NDS has a 35000, GBA has 30833, and BOX will have 5000. This is the standard pretimer for those games.
void blisytv::on_consoleBox_activated(const QString &arg1)
{
Methodbox();
Pretimer();
}

//this is the lag selector for whichever rng method you're using
void blisytv::on_methodbox_activated(const QString &arg1)
{
   Methodbox();
}


//this is for the  TeachyTV Target button.
void blisytv::on_pushButton_clicked()
    {



    ui->pushButton_3->setEnabled(true);


    //calls settings
    Settings();

    //this is code for calculating your target teachytv frame, and total target frame
    int introtimerframes;

    introtimerframes = introtimerms / 1000 * frameRate;
    int outoftvf;
    targetf = ui -> targetframe->value();
    outoftvf = ui -> outoftvframe->value();

    //you add and subtract 33 here, because entering the tv is 34 frames of lag, and leaving it is 1 frame of lag, so you combine the value and compensate on both ends.
    //ie you'll always be 34 frames too long outside, and 34 frames too short in the tv, and 1 frame too long in the tv, and 1 frame too short outside.
    int totaltvf = (targetf - outoftvf)/313 + 33;
    long double remain = (targetf - outoftvf) % 313;
    int outsidetv = (remain + outoftvf) - 33;
    totaloutput = totaltvf + outsidetv + ui->delaybox->value();
    ui->output1->setValue(totaloutput);
    ui->output2->setValue(totaltvf);
    ui->outputms1->setValue((1 / frameRate * 1000 * totaloutput) + introtimerms);
    ui->outputms2->setValue(1 / frameRate * 1000 * totaltvf);






    //this sets these values to the current output of outputms1/2 for later in the update flowtimer section.
    secrettarget = ui->outputms1->value() - introtimerms;
    secrettv = ui->outputms2->value();
    //this is so when you change target frames, the calibrate values don't mess with it if they're there from a previous rng.
    ui->outputadjust2->setValue(0);
    ui->outputadjust1->setValue(0);
    ui->outputmsadjust2->setValue(0);
    ui->outputmsadjust1->setValue(0);





}

//This is for the adjust calculate button
void blisytv::on_pushButton_2_clicked()
{


    ui->pushButton_3->setEnabled(true);

    //calls settings value
    Settings();

    //this is the math for calibrating. It prioritizes as much time in teachytv by looking to see if the remainder is greater than or less than 156.
    //If it is greater than or equal to it, it increases your tv frame by 1, and subtracts the remainder from out of tv frames.
    int frameHit;
    frameHit = ui->frameHit->value();
    int adjtv;
    adjtv = targetf - frameHit;
    long double adjtv2;
    adjtv2 = adjtv / 313;
    long double adjout;
    adjout = adjtv % 313;
    if( adjout >= 156){
    adjout = -313 + adjout;
    adjtv2++;
    } else if ( adjout > -156){
    }else {
    adjout = 313 + adjout;
    adjtv2--;
    }
    ui->outputadjust2->setValue(adjtv2);
    ui->outputadjust1->setValue(adjout + adjtv2);
    long double totalmsout;
    totalmsout = adjtv2 / frameRate * 1000;
    long double totaltvout;
    totaltvout = adjout / frameRate * 1000;
    ui->outputmsadjust2->setValue(adjtv2 / frameRate * 1000);
    ui->outputmsadjust1->setValue(totalmsout + totaltvout);


}



//this sets everything to 0 in the adjust column in case you hit it by accident.
void blisytv::on_clear_clicked()
{
    ui->outputadjust2->setValue(0);
    ui->outputadjust1->setValue(0);
    ui->outputmsadjust2->setValue(0);
    ui->outputmsadjust1->setValue(0);

}







//I should've named the pushbuttons, oh well. This one is for the flowtimer calculator tab, pushing it converts the int in converttargetframe spinbox
//to ms and adds all the flowtimer info.
void blisytv::on_pushButton_4_clicked()
{
    //sets frame hit box and adjustment value to zero when you choose a new target frame.
    ui->convertertargetframehit->setValue(0);
    ui->adjustedby->setValue(0);
    //calls settings
        Settings();
        //setting ints and qstrings for this page
        int targetflowtimercalculator;
        int flowtimerout;
        int introtimerint;
        QString flowtimeroutput;
        QString SIDCHECK;
        QString introtimerstring;
        QString flowtimerpure;
        QString flowtimerforsid;
        introtimerint = introtimerms;
        targetflowtimercalculator = (1 / frameRate * 1000) * (ui->convertertargetframe->value() + ui->delaybox->value());
        flowtimerout = targetflowtimercalculator + introtimerms;
        flowtimerpure = QString::number(flowtimerout);
        introtimerstring = QString::number(ui->introtimer->value());
    //if abrabox is checked it adds abratimer to it, otherwise it doesn't.
         if (ui->abrabox->isChecked()){
        flowtimeroutput = flowtimerpure + "/" + introtimerstring + "/" + abratimerms;
         }else{
             flowtimeroutput = flowtimerpure + "/" + introtimerstring;
         }

    //if sid is checked, it won't add the intro timer to the ms conversion at all.
        SIDCHECK = ui->methodbox->currentText();
        int onlyflowtimer;
        onlyflowtimer = (1 / frameRate * 1000) * (ui->convertertargetframe->value() + delayboxvalue);
        flowtimerforsid = QString::number(onlyflowtimer);

        if(SIDCHECK == "SID"){

        ui->flowtimerout->setText(flowtimerforsid);
        }else{
        ui->flowtimerout->setText(flowtimeroutput);
        }
        secretflowtarget = targetflowtimercalculator;
        secretframehit = ui->convertertargetframe->value();


    }



//standard flowtimer adjustment
void blisytv::on_pushButton_7_clicked()
{
    //calls settings values
    Settings();
   int framehit;
   int adjustby;
   framehit = ui->convertertargetframehit->value();
   adjustby = secretframehit - framehit + ui->adjustedby->value();
   ui->adjustedby->setValue(adjustby);




}

//flowtimer adjustment output
void blisytv::on_pushButton_6_clicked()
{
    //calls settings values
    Settings();
    int introtimerint;
    int adjustedframe;
    int adjustms;
    int adjustedms;
    int adjustmentout;
    QString flowtimeroutput;
    QString adjustedmsstring;
    QString introtimerstring;
    QString flowtimerout;
    QString SIDCHECK;
    introtimerint = introtimerms;
    adjustedframe = ui->convertertargetframehit->value() + ui->adjustedby->value();
    adjustms = 1 / frameRate * 1000 * ui->adjustedby->value();
    adjustedms = ((1 / frameRate * 1000) * (ui->convertertargetframe->value() + ui->delaybox->value())) + adjustms;
    adjustmentout = adjustedms + introtimerms;
    flowtimeroutput = QString::number(adjustmentout);
    introtimerstring = QString::number(ui->introtimer->value());

    if (ui->abrabox->isChecked()){
   flowtimerout = flowtimeroutput + "/" + introtimerstring + "/" + abratimerms;
    }else{
        flowtimerout = flowtimeroutput + "/" + introtimerstring;
    }

    SIDCHECK = ui->methodbox->currentText();

    adjustedmsstring = QString::number(adjustedms);

    if(SIDCHECK == "SID"){

    ui->flowtimerouthit->setText(adjustedmsstring);
    }else{
    ui->flowtimerouthit->setText(flowtimerout);
    }
    ui->flowtimerouthit->selectAll();
    ui->flowtimerouthit->copy();
}


blisytv::~blisytv()
{





    delete ui;
}



void blisytv::flowtimer()
{

    Settings();

    //setting int and qstrings for this function, the qstrings just become qstringnumbers

    QString flowtimertotal;
    QString flowtimertv;
    QString introtimer;
    int originalflowtimer;
    int originalflowtimertv;
    int flowtimer;
    int flowtimerteli;
    int introtimer1;
    int invisiblecurrenttarget;
    int invisibletvtarget;

    long double introtimerframes;

    introtimerframes = introtimerms / 1000 * frameRate;

    //this gets value from the 35000 ms intro timer box and turns it into a qstring for when its output
    introtimer1 = ui->introtimer->value();
    introtimer = QString::number(introtimer1);

    //these are the adjustment values
    flowtimerteli = ui->outputmsadjust2->value();
    flowtimer = ui->outputmsadjust1->value();


    //these are the values from the original calculation button
    originalflowtimer = secrettarget +  (1 / frameRate * 1000 * introtimerframes);
    originalflowtimertv = secrettv;

    invisiblecurrenttarget = originalflowtimer + flowtimer;
    invisibletvtarget = originalflowtimertv + flowtimerteli;

    //This adds the original calibration value with the adjustment value while it's in a qstring
    flowtimertotal = QString::number(invisiblecurrenttarget);

    //this checks to esee if abrabox is checked, and if it is adds abratimerms to the output for the flow timer copy/paste, if it's unchecked it doesn't output that value.
    if (ui->abrabox->isChecked()){
        ui->flow1->setText( flowtimertotal + "/" + introtimer + "/" + abratimerms);
    } else{
    ui->flow1->setText( flowtimertotal + "/" + introtimer);
    }


    //sets the teachytv value for flowtimer box
    flowtimertv = QString::number(invisibletvtarget);
    ui->flowtv->setText(flowtimertv);


    //this sets these values to our former flowtimer values, so when you click update it doesn't update from the original "total ms" and "tv ms" every time, it updates continuously.
    secrettv = invisibletvtarget;
    secrettarget = invisiblecurrenttarget - (1 / frameRate * 1000 * introtimerframes);

    ui->pushButton_3->setEnabled(false);




}

void blisytv::on_pushButton_3_clicked()
{
    flowtimer();
}

void blisytv::on_pushButton_5_clicked()
{
  ui->flowtimerout->selectAll();
  ui->flowtimerout->copy();
}


void blisytv::on_pushButton_8_clicked()
{
    ui->flow1->selectAll();
    ui->flow1->copy();
}

void blisytv::on_pushButton_9_clicked()
{
    ui->flowtv->selectAll();
    ui->flowtv->copy();
}



void blisytv::on_versionBox_activated(const QString &arg1)
{
Methodbox();
Pretimer();
}


void blisytv::on_manualbox_stateChanged(int arg1)
{
    if(ui->manualbox->isChecked()){
        ui->outputadjust1->setReadOnly(false);
        ui->outputadjust2->setReadOnly(false);
        ui->outputmsadjust1->setReadOnly(false);
        ui->outputmsadjust2->setReadOnly(false);

    }else{

        ui->outputadjust1->setReadOnly(true);
        ui->outputadjust2->setReadOnly(true);
        ui->outputmsadjust1->setReadOnly(true);
        ui->outputmsadjust2->setReadOnly(true);
    }

}
