#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QDialog>
#include<qtextbrowser.h>
#include "binary_tree.h"
#include "math.h"



QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QDialog
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();

private slots:
    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_zero_clicked();

    void on_dot_clicked();

    void on_add_clicked();

    void on_minus_clicked();

    void on_mul_clicked();

    void on_div_clicked();

    void on_pow_clicked();

    void on_p_c_clicked();

    void on_p_o_clicked();

    void on_back_clicked();

    void on_clear_clicked();

    void on_equal_clicked();

    void on_history_clicked();

    void on_step_clicked();
    void changeCaption();

    void on_tree_clicked();

    void on_tan_clicked();

    void on_cos_clicked();

    void on_sin_clicked();

private:
    QString postfix="";
    Ui::calculator *ui;
    QList<QString> steps;
    QList<QString> history;
     bool is_character(char x);
     bool Error_control(QString p);
     QString in_to_post(QString p);
     int precedence(QString x);
     QString evaluate(QString x,QList<QString> * steps, QList<QString>* history);
     QString infix="";
     QString post_to_in(QString x);






};
#endif // CALCULATOR_H
