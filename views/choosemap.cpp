#include "choosemap.h"


ChooseMap::ChooseMap(QWidget *parent)
    : QWidget{parent}
{


    layOut = make_unique<QVBoxLayout>(this);
    hLayOut = make_unique<QHBoxLayout>(this);

    label = make_unique<QLabel>(this);
    label->setAlignment(Qt::AlignCenter);
    label->setText("Choose Map");
    QFont font("Arial", 30, QFont::Bold);
    label->setFont(font);




    layOut->addWidget(label.get());
    layOut->addSpacing(10);
    layOut->setAlignment(Qt::AlignCenter);
    layOut->addLayout(hLayOut.get());

    for (auto& map : maps)
    {
        std::unique_ptr<QPushButton> mapButton = make_unique<QPushButton>(this);
        QPixmap pixMap(map);
        mapButton->setIcon(QIcon(pixMap));
        mapButton->setIconSize(QSize(mapSize, mapSize));
        hLayOut->addWidget(mapButton.get());
        connect(mapButton.get(), &QPushButton::clicked, this, [=]{
             emit choose(map);
            });

        mapButtons.push_back(std::move(mapButton));

    }

}

