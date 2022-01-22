#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <framelesshelper/qtacrylicmainwindow.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
namespace Ui { class TitleBar; }

class QWebEngineView;
QT_END_NAMESPACE

class MainWindow : public QtAcrylicMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initForm();
    void initWebView();

private:
    Ui::MainWindow *ui;
    Ui::TitleBar *titlebar;

    QWebEngineView *webView;
};
#endif // MAINWINDOW_H
