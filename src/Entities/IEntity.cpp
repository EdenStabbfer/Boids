//
// Created by kufuk on 27.08.2023.
//

#include "../../include/Entities/IEntity.h"

uint32_t IEntity::generateId()
{
    static uint32_t counter{0};
    return counter++;
}

IEntity::IEntity()
{
    this->_id = generateId();
}

bool IEntity::operator==(const IEntity &other) const
{
    return this->_id == other._id;
}

bool IEntity::operator!=(const IEntity &other) const
{
    return this->_id != other._id;
}

uint32_t IEntity::getId() const
{
    return _id;
}

