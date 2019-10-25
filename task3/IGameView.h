//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK3_IGAMEVIEW_H
#define TASK3_IGAMEVIEW_H


class IGameView {
    virtual ~IGameView() = default;
    virtual void draw() = 0;
    virtual void clear() = 0;

};


#endif //TASK3_IGAMEVIEW_H
