#pragma once

class IWorker{
public:
    virtual void Execute() const;
    virtual ~IWorker();
}