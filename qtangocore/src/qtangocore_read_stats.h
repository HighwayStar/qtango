#ifndef QTANGO_READ_STATS_H
#define QTANGO_READ_STATS_H

#include <QString>
#include <QMap>
#include <QList>
#include <QTime>
#include <QMutex>
#include <QObject>


#define STATS_OBJINFO(obj) (QTangoCoreReadStats::instance()->enabled() ? (QString("name \"%1\" thread \"%2\"").arg(obj != NULL  ? obj->objectName() : "NULL").arg(QThread::currentThread() != NULL ? QThread::currentThread()->objectName() : "NULL")) : QString() )

/** \brief initializes the statistics infrastructure
 *
 * Initiates the statistic singleton. It is not strictly necessary to call this, but you can
 * if you want to have the object already instantiated in memory when adding elements to the stats.
 * If this is not called, the instance of the class is created when one of its methods are called.
 */
#define INIT_STATS() (QTangoCoreReadStats::instance())


/** \brief add to the statistics an element with a certain name
 *
 * Add to the statistics an element with a certain name, for instance an attribute name.
 * The name will be associated to a timestamp and the data represented by the name will be
 * considered without any error and will be stored without any particular message.
 *
 * @see ADD_READ_STAT_MSG
 * @see ADD_READ_STAT_EVENT
 * @see ADD_READ_STAT_ERR
 * @see ADD_READ_STAT_EVENT_ERR
 * @see ADD_READ_STAT_EVENT_ERR_MSG
 */
#define ADD_READ_STAT(name, objinfo) (QTangoCoreReadStats::instance()->addAttributeStat(name, objinfo) );

/** \brief add to the statistics an element with a certain name and associate a message
 *
 * The same as ADD_READ_STAT, but also associates a message to the statistic entry.
 */
#define ADD_READ_STAT_MSG(name, message, objinfo) (QTangoCoreReadStats::instance()->addAttributeStat(name, objinfo, false , false , message) )

/** \brief add to the statistics an element with a certain name and mark it as an event
 * 
 * The same as ADD_READ_STAT, but it keeps track that the element was generated by an event
 */
#define ADD_READ_STAT_EVENT(name, objinfo) \
  (QTangoCoreReadStats::instance()->addAttributeStat(name, objinfo, true))
  
/** \brief add to the statistics an element, but mark it with an error flag
 * 
 * The same as ADD_READ_STAT, but the element is added to the statistic set marked with an error flag.
 */
#define ADD_READ_STAT_ERR(name, objinfo) (QTangoCoreReadStats::instance()->addAttributeStat(name, objinfo, false, true)

#define ADD_READ_STAT_EVENT_MSG(name, message, objinfo) (QTangoCoreReadStats::instance()->addAttributeStat(name, objinfo, true, false, message))

#define ADD_READ_STAT_ERR_MSG(name, message, objinfo) (QTangoCoreReadStats::instance()->addAttributeStat(name, objinfo, false, true, message)

#define ADD_READ_STAT_EVENT_ERR(name, objinfo) (QTangoCoreReadStats::instance()->addAttributeStat(name, objinfo, true, true)

#define ADD_READ_STAT_EVENT_ERR_MSG(name, message, objinfo) (QTangoCoreReadStats::instance()->addAttributeStat(name, objinfo, true, true, message)

/** \brief save the statistics on a csv file.
 *
 * Saves the gathered statistics on a csv file. The file name will be made up of the application name
 * and the start - stop execution timestamps.
 */
#define DUMP_STATS() (QTangoCoreReadStats::instance()->dumpStats())

/** \brief the same as DUMP_STATS
 *
 * The same as DUMP_STATS(), an alias provided for convenience.
 */
#define SAVE_STATS() DUMP_STATS()

/** \brief obtain the file name of a previously saved statistic session.
 *
 * @return a QString with the name of the file saved. DUMP_STATS() must be called before
 *         otherwise the string returned will be an empty QString.
 */
#define STATS_SAVED_FILENAME() (QTangoCoreReadStats::instance()->savedFilename())


class StatsData
{
  public:
     StatsData(QString name, QString objinfo, QTime t, bool event, bool error, QString message);
    
    StatsData() { d_empty = true; }
    
    QString name() { return d_name; }
    bool error() { return d_error; }
    bool event() { return d_event; }
    QTime timestamp() { return d_timestamp; }
    QString message() { return d_message; }
    QString objInfo() { return d_objinfo; }
    bool isEmpty() { return d_empty; }
    
    private:
      QString d_name;
      bool d_error, d_event, d_empty;
      QString d_message, d_objinfo;
      QTime d_timestamp;
};

class QTangoCoreReadStats
{
  public:
    static QTangoCoreReadStats * instance();
    
    void addAttributeStat(const QString &attName, const QString& objinformation, bool event = false, 
      bool error = false, const QString &msg = QString());
    
    QList <StatsData> statsForName(const QString &name);
    
    bool dumpStats();
    
    bool enabled() { return d_enabled; }
    
    QString savedFilename() { return d_savedFilename; }
    
  private:
  
    QTangoCoreReadStats();
    
    static QTangoCoreReadStats *_instance;
    
    bool d_enabled;
    bool d_pollEnabled;
    bool d_eventEnabled;
    
    QMap<QString, QList <StatsData> > d_statsMap;
    QTime d_startTime;
    QString d_savedFilename, d_applicationName;
    QMutex d_mutex;
};




#endif
