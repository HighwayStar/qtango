/*
 * This file was generated by dbusxml2cpp version 0.6
 * Command line was: dbusxml2cpp ActionFactory.xml -c ActionFactoryInterface -p ActionFactoryInterface
 *
 * dbusxml2cpp is Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef ACTIONFACTORYINTERFACE_H_1284122990
#define ACTIONFACTORYINTERFACE_H_1284122990

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface it.elettra.trieste.TApplicationsInterface.actionFactory
 */
class ActionFactoryInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "it.elettra.trieste.TApplicationsInterface.actionFactory"; }

public:
    ActionFactoryInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~ActionFactoryInterface();

    Q_PROPERTY(QStringList actionsListAsXml READ actionsListAsXml)
    inline QStringList actionsListAsXml() const
    { return qvariant_cast< QStringList >(internalPropGet("actionsListAsXml")); }

    Q_PROPERTY(bool targetExecutionLogEnabled READ targetExecutionLogEnabled)
    inline bool targetExecutionLogEnabled() const
    { return qvariant_cast< bool >(internalPropGet("targetExecutionLogEnabled")); }

public Q_SLOTS: // METHODS
    inline QDBusReply<QString> actionAsXml(const QString &point, const QStringList &args, int desiredRefreshMode)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(point) << qVariantFromValue(args) << qVariantFromValue(desiredRefreshMode);
        return callWithArgumentList(QDBus::Block, QLatin1String("actionAsXml"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void targetExecuted(const QString &point, int timestamp, bool success, const QString &exception, const QString &data);
};

namespace it {
  namespace elettra {
    namespace trieste {
      namespace TApplicationsInterface {
        typedef ::ActionFactoryInterface actionFactory;
      }
    }
  }
}
#endif
