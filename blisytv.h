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

    void on_pushButton_3_clicked();

    void on_clear_clicked();

private:
    Ui::blisytv *ui;
};
#endif // BLISYTV_H
