#include "commandedit.h"
#include "qevent.h"

CommandEdit::CommandEdit(QWidget *parent)
    : QTextEdit{parent}
{

}

void CommandEdit::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Return)
    {
     emit submitCommand(toPlainText());
    }
    else
    {
        QTextEdit::keyPressEvent(event);
    }
}
