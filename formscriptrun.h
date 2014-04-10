#ifndef FORMSCRIPTRUN_H
#define FORMSCRIPTRUN_H

#include <QWidget>
#include <QApplication>

namespace Ui {
    class FormScriptRun;
}

class FormScriptRun : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormScriptRun(QWidget *parent = 0);
    ~FormScriptRun();
    
private slots:
    void on_tButtonRunScript_clicked();

private:
    Ui::FormScriptRun *ui;

protected:
    void closeEvent(QCloseEvent *) { qApp->quit(); }
};

#endif // FORMSCRIPTRUN_H
