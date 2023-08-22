#ifndef COMMANDEDIT_H
#define COMMANDEDIT_H

#include <QTextEdit>

class CommandEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit CommandEdit(QWidget *parent = nullptr);




signals:

    void submitCommand(QString command);

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // COMMANDEDIT_H
