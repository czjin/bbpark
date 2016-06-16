#include "versioncontroller.h"
#include "version.h"


VersionController::VersionController(const VersionController &)
    : ApplicationController()
{ }

void VersionController::index()
{
    QList<Version> versionList = Version::getAll();
    texport(versionList);
    render();
}

void VersionController::show(const QString &pk)
{
    auto version = Version::get(pk.toInt());
    texport(version);
    render();
}

void VersionController::entry()
{
    renderEntry();
}

void VersionController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("version");
    auto version = Version::create(form);
    if (!version.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", version.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void VersionController::renderEntry(const QVariantMap &version)
{
    texport(version);
    render("entry");
}

void VersionController::edit(const QString &pk)
{
    auto version = Version::get(pk.toInt());
    if (!version.isNull()) {
        renderEdit(version.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void VersionController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto version = Version::get(pk.toInt());
    if (version.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("version");
    version.setProperties(form);
    if (version.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void VersionController::renderEdit(const QVariantMap &version)
{
    texport(version);
    render("edit");
}

void VersionController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto version = Version::get(pk.toInt());
    version.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(versioncontroller)
