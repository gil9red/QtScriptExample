#include <QtGui/QApplication>
#include "note.h"

//#include <QtScriptTools/QScriptEngineDebugger>
#include "Script/scriptengine.h"

#include <QMetaProperty>

#include <QDebug>
#include <QTextCodec>

#include "formscriptrun.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "utf8" ) );
    QApplication app(argc, argv);

    QScriptEngine * engine = Script::ScriptEngine::instance();

    Note note;
    QScriptValue scriptNote = engine->newQObject( &note );
    engine->globalObject().setProperty( "note", scriptNote );

    QScriptValue noteClass = engine->scriptValueFromQMetaObject < Note > ();
    engine->globalObject().setProperty( "Note", noteClass );

//    QScriptEngineDebugger debugger;
//    debugger.attachTo( engine );

    FormScriptRun form;
    form.show();

//    QScriptValue noteClass = engine.scriptValueFromQMetaObject < Note > ();
//    engine.globalObject().setProperty( "Note", noteClass );
//    engine.evaluate( "var n = new Note; n.show(); n.text = 'Eat'; n = null;" );
//    qDebug() << engine.globalObject().property( "n" ).toQObject()->property( "text" );

//    int count = note.metaObject()->propertyCount();
//    for ( int i = 0; i < count; i++ )
//    {
//        const char * name = note.metaObject()->property(i).name();
//        qDebug() << name << note.property( name );
//    }

    return app.exec();
}
