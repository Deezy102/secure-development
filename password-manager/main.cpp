#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlProperty>
#include <QDebug>

#include "credslist.h"
#include "credsmodel.h"
#include "authmanager.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);


    qmlRegisterType<CredsModel>("Creds", 1, 0, "CredsModel");
    qmlRegisterUncreatableType<CredsList>("Creds",1,0,"CredsList", QStringLiteral("CredsList should not be created in QML"));


    AuthManager authManager;
    CredsList credsList;

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("authManager", &authManager);
    context->setContextProperty("credsList", &credsList);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
