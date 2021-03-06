/*
 * This file was generated by dbusxml2cpp version 0.6
 * Command line was: dbusxml2cpp TApplication.xml -a TApplicationAdaptor.h -c TApplicationAdaptor
 *
 * dbusxml2cpp is Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef TAPPLICATIONADAPTOR_H_1291642375
#define TAPPLICATIONADAPTOR_H_1291642375

#include <QtCore/QObject>
#include <QtCore/QMetaObject>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Adaptor class for interface it.elettra.trieste.TApplicationsInterface
 */
class TApplicationAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "it.elettra.trieste.TApplicationsInterface")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"it.elettra.trieste.TApplicationsInterface\" >\n"
"    <method name=\"message\" />\n"
"    <method name=\"version\" >\n"
"      <arg direction=\"out\" type=\"s\" />\n"
"    </method>\n"
"    <!-- 5 input arguments signature -->\n"
"    <method name=\"invokeMethod5\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"widgetName\" />\n"
"      <arg direction=\"in\" type=\"s\" name=\"member\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val0\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val1\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val2\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val3\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val4\" />\n"
"      <arg direction=\"out\" type=\"v\" name=\"value\" />\n"
"    </method>\n"
"    <!-- 4 input arguments signature -->\n"
"    <method name=\"invokeMethod4\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"widgetName\" />\n"
"      <arg direction=\"in\" type=\"s\" name=\"member\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val0\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val1\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val2\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val3\" />\n"
"      <arg direction=\"out\" type=\"v\" name=\"value\" />\n"
"    </method>\n"
"    <!-- 3 input arguments signature -->\n"
"    <method name=\"invokeMethod3\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"widgetName\" />\n"
"      <arg direction=\"in\" type=\"s\" name=\"member\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val0\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val1\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val2\" />\n"
"      <arg direction=\"out\" type=\"v\" name=\"value\" />\n"
"    </method>\n"
"    <!-- 2 input arguments signature -->\n"
"    <method name=\"invokeMethod2\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"widgetName\" />\n"
"      <arg direction=\"in\" type=\"s\" name=\"member\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val0\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val1\" />\n"
"      <arg direction=\"out\" type=\"v\" name=\"value\" />\n"
"    </method>\n"
"    <!-- 1 input arguments signature -->\n"
"    <method name=\"invokeMethod1\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"widgetName\" />\n"
"      <arg direction=\"in\" type=\"s\" name=\"member\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"val0\" />\n"
"      <arg direction=\"out\" type=\"v\" name=\"value\" />\n"
"    </method>\n"
"    <!-- 0 input arguments signature -->\n"
"    <method name=\"invokeMethod0\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"widgetName\" />\n"
"      <arg direction=\"in\" type=\"s\" name=\"member\" />\n"
"      <arg direction=\"out\" type=\"v\" name=\"value\" />\n"
"    </method>\n"
"    <method name=\"readProperty\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"objectName\" />\n"
"      <arg direction=\"in\" type=\"s\" name=\"propertyName\" />\n"
"      <arg direction=\"out\" type=\"v\" name=\"value\" />\n"
"    </method>\n"
"    <method name=\"writeProperty\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"objectName\" />\n"
"      <arg direction=\"in\" type=\"s\" name=\"propertyName\" />\n"
"      <arg direction=\"in\" type=\"v\" name=\"value\" />\n"
"    </method>\n"
"    <method name=\"raise\" />\n"
"    <method name=\"quit\" />\n"
"    <method name=\"onSecondInstanceDetected\" />\n"
"    <method name=\"widgetList\" >\n"
"      <arg direction=\"out\" type=\"as\" />\n"
"    </method>\n"
"    <method name=\"executable\" >\n"
"      <arg direction=\"out\" type=\"s\" />\n"
"    </method>\n"
"    <method name=\"methods\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"widgetName\" />\n"
"      <arg direction=\"out\" type=\"as\" />\n"
"    </method>\n"
"    <method name=\"properties\" >\n"
"      <arg direction=\"in\" type=\"s\" name=\"widgetName\" />\n"
"      <arg direction=\"out\" type=\"as\" />\n"
"    </method>\n"
"    <method name=\"parameters\" >\n"
"      <arg direction=\"out\" type=\"as\" />\n"
"    </method>\n"
"    <property access=\"readwrite\" type=\"b\" name=\"unique\" />\n"
"    <signal name=\"applicationStarted\" />\n"
"  </interface>\n"
        "")
public:
    TApplicationAdaptor(QObject *parent);
    virtual ~TApplicationAdaptor();

public: // PROPERTIES
    Q_PROPERTY(bool unique READ unique WRITE setUnique)
    bool unique() const;
    void setUnique(bool value);

public Q_SLOTS: // METHODS
    QString executable();
    QDBusVariant invokeMethod0(const QString &widgetName, const QString &member);
    QDBusVariant invokeMethod1(const QString &widgetName, const QString &member, const QDBusVariant &val0);
    QDBusVariant invokeMethod2(const QString &widgetName, const QString &member, const QDBusVariant &val0, const QDBusVariant &val1);
    QDBusVariant invokeMethod3(const QString &widgetName, const QString &member, const QDBusVariant &val0, const QDBusVariant &val1, const QDBusVariant &val2);
    QDBusVariant invokeMethod4(const QString &widgetName, const QString &member, const QDBusVariant &val0, const QDBusVariant &val1, const QDBusVariant &val2, const QDBusVariant &val3);
    QDBusVariant invokeMethod5(const QString &widgetName, const QString &member, const QDBusVariant &val0, const QDBusVariant &val1, const QDBusVariant &val2, const QDBusVariant &val3, const QDBusVariant &val4);
    void message();
    QStringList methods(const QString &widgetName);
    void onSecondInstanceDetected();
    QStringList parameters();
    QStringList properties(const QString &widgetName);
    void quit();
    void raise();
    QDBusVariant readProperty(const QString &objectName, const QString &propertyName);
    QString version();
    QStringList widgetList();
    void writeProperty(const QString &objectName, const QString &propertyName, const QDBusVariant &value);
Q_SIGNALS: // SIGNALS
    void applicationStarted();
};

#endif
