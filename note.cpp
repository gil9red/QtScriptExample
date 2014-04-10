#include "note.h"
#include <QVBoxLayout>

Note::Note(QWidget *parent) :
    QWidget(parent),
    lEditName( new QLineEdit() ),
    tEditText( new QTextEdit() )
{
    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->addWidget( lEditName );
    mainLayout->addWidget( tEditText );
    setLayout( mainLayout );
}
