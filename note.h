#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>

class Note : public QWidget
{
    Q_OBJECT
    Q_PROPERTY( QString name READ getName WRITE setName )
    Q_PROPERTY( QString text READ getText WRITE setText )
    Q_PROPERTY( QPoint pos READ getPos WRITE setPos )
    Q_PROPERTY( QPoint pos READ getPos WRITE move )
    Q_PROPERTY( addNew RESET )
    Q_PROPERTY( addNews RESET )

public:
    explicit Note(QWidget *parent = 0);
    
public slots:
    QString getName() { return lEditName->text(); }
    void setName( const QString & name ) { return lEditName->setText( name ); }

    QString getText() { return tEditText->toHtml(); }
    void setText( const QString & text ) { return tEditText->setText( text ); }

    QPoint getPos() { return pos(); }
    void setPos( const QPoint & pos ) { QWidget::move( pos ); }
    void setPos( int x, int y ) { setPos( QPoint( x, y ) ); }

    void move(const QPoint & pos) { QWidget::move( pos ); }
    void move(int x, int y) { move( QPoint( x, y ) ); }

    void addNew() { Note * n = new Note(); n->show(); }
    void addNews( int count ) { while ( count-- ) addNew(); }

private:
    QLineEdit * lEditName;
    QTextEdit * tEditText;
};

#include <QtScript/QScriptEngine>
Q_SCRIPT_DECLARE_QMETAOBJECT( Note, QWidget * )

#endif // NOTE_H
