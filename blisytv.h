#ifndef BLISYTV_H
#define BLISYTV_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class blisytv; }
QT_END_NAMESPACE

class blisytv : public QMainWindow
{
    Q_OBJECT

public:
    blisytv(QWidget *parent = nullptr);
    ~blisytv();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void Pretimer();
    void on_clear_clicked();
    void Settings();
    void Methodbox();
    void on_methodbox_activated(const QString &arg1);

    void on_pushButton_4_clicked();


    void on_pushButton_7_clicked();
    void flowtimer();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_consoleBox_activated(const QString &arg1);

    void on_versionBox_activated(const QString &arg1);

private:
    Ui::blisytv *ui;
};
#endif // BLISYTV_H
