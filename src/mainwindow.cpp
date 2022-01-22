#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_titlebar.h"

#include <QMenuBar>
#include <QStyleOption>
#include <QToolButton>
#include <QWebEngineView>
#include <QWebChannel>
#include <QDebug>

#include <unordered_set>

#include "framelesshelper/framelesswindowsmanager.h"

#include "core/messagehandle.h"

MainWindow::MainWindow(QWidget *parent)
    : QtAcrylicMainWindow(parent)
    , ui(new Ui::MainWindow)
    , titlebar(new Ui::TitleBar)
    , webView(new QWebEngineView(this))
{
    ui->setupUi(this);

    initForm();
    initWebView();
}

MainWindow::~MainWindow()
{
    delete titlebar;
    delete ui;
}

void MainWindow::initForm()
{
    QWidget *widget = new QWidget(this);
    titlebar->setupUi(widget);

    auto menubar =  menuBar();
    titlebar->menuLayout->setMenuBar(menubar);
    setMenuWidget(widget);

    int maxH = 0;
    int maxW = 50;
    for(QAction* act: menubar->actions()) {
        QRect r = menubar->actionGeometry(act);
        if(r.height() > maxH)
            maxH = r.height();
        maxW += r.width();
    }
    titlebar->menuWidget->setFixedSize(maxW,maxH);

    connect(this, &QMainWindow::windowIconChanged, titlebar->iconButton, &QPushButton::setIcon);
    connect(this, &QMainWindow::windowTitleChanged, titlebar->titleLabel, &QLabel::setText);
    connect(titlebar->closeButton, &QPushButton::clicked, this, &QMainWindow::close);
    connect(titlebar->minimizeButton, &QPushButton::clicked, this, &QMainWindow::showMinimized);
    connect(titlebar->maximizeButton, &QPushButton::clicked, [this](){
        if (this->isMaximized() || this->isFullScreen()) {
            this->showNormal();
        } else {
            this->showMaximized();
        }
    });
    connect(this, &QtAcrylicMainWindow::windowStateChanged, [this](){
        titlebar->maximizeButton->setChecked(this->isMaximized());
        titlebar->maximizeButton->setToolTip(this->isMaximized() ? QObject::tr("Restore") : QObject::tr("Maximize"));
    });
    connect(titlebar->iconButton, &QPushButton::clicked, this, &QtAcrylicMainWindow::displaySystemMenu);

    QStyleOption option;
    option.initFrom(this);
    const QIcon icon = this->style()->standardIcon(QStyle::SP_DirIcon, &option);
    this->setWindowIcon(icon);

    //    setAcrylicEnabled(true);
    //    setTintOpacity(0.1);

    createWinId(); // Qt's internal function, make sure it's a top level window.
    const QWindow *win = windowHandle();

    FramelessWindowsManager::addWindow(win);
    FramelessWindowsManager::addIgnoreObject(win, titlebar->iconButton);
    FramelessWindowsManager::addIgnoreObject(win, titlebar->minimizeButton);
    FramelessWindowsManager::addIgnoreObject(win, titlebar->maximizeButton);
    FramelessWindowsManager::addIgnoreObject(win, titlebar->closeButton);
    FramelessWindowsManager::addIgnoreObject(win, titlebar->menuWidget);
    //    FramelessWindowsManager::addIgnoreObject(win, titlebar->searchWidget);
}

void MainWindow::initWebView()
{
    setCentralWidget(webView);

    QWebChannel *webChannel = new QWebChannel(webView);
    webChannel->registerObject("qHandle", new MessageHandle);

    webView->page()->setWebChannel(webChannel);
//    webView->setUrl(QUrl("D:/QWorkSpace/SYFileManager/src/ui/app/index.html"));
    webView->setUrl(QUrl("D:/QWorkSpace/SYFileManager/src/ui/app-cli/dist/index.html"));
}

