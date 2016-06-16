#include "sysinfocontroller.h"
#include "sysinfo.h"


SysinfoController::SysinfoController(const SysinfoController &)
    : ApplicationController()
{ }

void SysinfoController::index()
{
    QList<Sysinfo> sysinfoList = Sysinfo::getAll();
    texport(sysinfoList);
    render();
}

void SysinfoController::show(const QString &pk)
{
    auto sysinfo = Sysinfo::get(pk.toInt());
    texport(sysinfo);
    render();
}

void SysinfoController::entry()
{
    renderEntry();
}

void SysinfoController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("sysinfo");
    auto sysinfo = Sysinfo::create(form);
    if (!sysinfo.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", sysinfo.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void SysinfoController::renderEntry(const QVariantMap &sysinfo)
{
    texport(sysinfo);
    render("entry");
}

void SysinfoController::edit(const QString &pk)
{
    auto sysinfo = Sysinfo::get(pk.toInt());
    if (!sysinfo.isNull()) {
        renderEdit(sysinfo.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void SysinfoController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto sysinfo = Sysinfo::get(pk.toInt());
    if (sysinfo.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("sysinfo");
    sysinfo.setProperties(form);
    if (sysinfo.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void SysinfoController::renderEdit(const QVariantMap &sysinfo)
{
    texport(sysinfo);
    render("edit");
}

void SysinfoController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto sysinfo = Sysinfo::get(pk.toInt());
    sysinfo.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(sysinfocontroller)
