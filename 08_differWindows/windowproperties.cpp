#include "windowproperties.h"
#include "ui_windowproperties.h"

WindowProperties::WindowProperties(QWidget *parent, Qt::WindowFlags f)
    : QWidget(parent, f)
    , ui(new Ui::WindowProperties)
{
    ui->setupUi(this);
    ui->windowType->setChecked(true);

    QObject::connect(ui->windowType, &QRadioButton::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->dialogType, &QRadioButton::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->sheetType, &QRadioButton::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->drawerType, &QRadioButton::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->popupType, &QRadioButton::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->toolType, &QRadioButton::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->tooltipType, &QRadioButton::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->splashType, &QRadioButton::toggled, this, &WindowProperties::typeToggled);

    QObject::connect(ui->MSFSDBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->X11BypassBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->FramelessBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->NoDropBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->titleBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->SystemMenuBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->CustomizeBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->minimizeBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->maximizeBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->closeBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->contextBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->shadeBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->onTopBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
    QObject::connect(ui->onBottomBox, &QCheckBox::toggled, this, &WindowProperties::typeToggled);
}

WindowProperties::~WindowProperties()
{
    delete ui;
}

void WindowProperties::typeToggled(bool)
{
    Qt::WindowFlags flags = Qt::Widget;
    checkProperties(flags);
    emit signalType(flags);
}

void WindowProperties::checkProperties(Qt::WindowFlags &flags) {
    if (ui->windowType->isChecked()) {
        flags = Qt::Window;
    } else if (ui->dialogType->isChecked()) {
        flags = Qt::Dialog;
    } else if (ui->sheetType->isChecked()) {
        flags = Qt::Sheet;
    } else if (ui->drawerType->isChecked()) {
        flags = Qt::Drawer;
    } else if (ui->popupType->isChecked()) {
        flags = Qt::Popup;
    } else if (ui->toolType->isChecked()) {
        flags = Qt::Tool;
    } else if (ui->tooltipType->isChecked()) {
        flags = Qt::ToolTip;
    } else if (ui->splashType->isChecked()) {
        flags = Qt::SplashScreen;
    }
    if (ui->MSFSDBox->isChecked()) {
        flags |= Qt::MSWindowsFixedSizeDialogHint;
    }
    if (ui->X11BypassBox->isChecked()) {
        flags |= Qt::X11BypassWindowManagerHint;
    }
    if (ui->FramelessBox->isChecked()) {
        flags |= Qt::FramelessWindowHint;
    }
    if (ui->NoDropBox->isChecked()) {
        flags |= Qt::NoDropShadowWindowHint;
    }
    if (ui->titleBox->isChecked()) {
        flags |= Qt::WindowTitleHint;
    }
    if (ui->SystemMenuBox->isChecked()) {
        flags |= Qt::WindowSystemMenuHint;
    }
    if (ui->minimizeBox->isChecked()) {
        flags |= Qt::WindowMinimizeButtonHint;
    }
    if (ui->maximizeBox->isChecked()) {
        flags |= Qt::WindowMaximizeButtonHint;
    }
    if (ui->closeBox->isChecked()) {
        flags |= Qt::WindowCloseButtonHint;
    }
    if (ui->contextBox->isChecked()) {
        flags |= Qt::WindowContextHelpButtonHint;
    }
    if (ui->shadeBox->isChecked()) {
        flags |= Qt::WindowShadeButtonHint;
    }
    if (ui->onTopBox->isChecked()) {
        flags |= Qt::WindowStaysOnTopHint;
    }
    if (ui->onBottomBox->isChecked()) {
        flags |= Qt::WindowStaysOnBottomHint;
    }
    if (ui->CustomizeBox->isChecked()) {
        flags |= Qt::CustomizeWindowHint;
    }
}


