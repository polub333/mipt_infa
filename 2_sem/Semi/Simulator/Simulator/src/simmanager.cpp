#include <include/simmanager.h>
#include <include/herbivorous.h>
#include <include/predator.h>
#include <include/obstacle.h>

SimManager::SimManager(i16 field_h, i16 field_w)
{
    field = new Field(field_h, field_w);
    total_buried = 0;
}

SimManager::~SimManager()
{
    delete field;
}

void SimManager::Step()
{
    system("cls");
    size_t index_max = entities.size();
    for(size_t index = 0; index < index_max; ++index){
        if(entities[index]->GetState() == EntityState::S_DEAD){
            continue;
        }
        entities[index]->Tick();
    }

    field->Tick();
    field->Render();

    {
        size_t write_ix = 0, read_ix = 0;
        while(read_ix < entities.size()){
            if(entities[read_ix]->GetState() == EntityState::S_ALIVE){
                entities[write_ix] = entities[read_ix];
                ++write_ix;
            }
            else{
                delete entities[read_ix];
            }
            ++read_ix;
        }
        entities.resize(write_ix);
        total_buried += read_ix - write_ix;
        std::cerr << "Done with funerals:\n"
                  << "\tAnimals alive: " << write_ix << std::endl
                  << "\tBuried: " << read_ix - write_ix << std::endl
                  << "\tTotal buried: " << total_buried << std::endl;
    }

/*
    i16 x, y;
    do{
        x = rand() % field->width;
        y = rand() % field->height;
    } while(field->GetCellByCoords({x, y})->GetEntity() != nullptr);
    Spawn<Herbivorous>({x, y}, 150);
    do{
        x = rand() % field->width;
        y = rand() % field->height;
    } while(field->GetCellByCoords({x, y})->GetEntity() != nullptr);
    Spawn<Predator>({x, y}, 150);
*/
}

void SimManager::RandomSpawn(i16 obstNum, i16 herbNum, i16 predNum)
{
    for(int i = 0; i < obstNum; ++i){
        i16 x, y;
        do{
            x = rand() % field->width;
            y = rand() % field->height;
        } while(field->GetCellByCoords({x, y})->GetEntity() != nullptr);
        Spawn<Obstacle>({x, y});
    }

    for(int i = 0; i < herbNum; ++i){
        i16 x, y;
        do{
            x = rand() % field->width;
            y = rand() % field->height;
        } while(field->GetCellByCoords({x, y})->GetEntity() != nullptr);
        Spawn<Herbivorous>({x, y});
    }

    for(int i = 0; i < predNum; ++i){
        i16 x, y;
        do{
            x = rand() % field->width;
            y = rand() % field->height;
        } while(field->GetCellByCoords({x, y})->GetEntity() != nullptr);
        Spawn<Predator>({x, y}, 150);
    }
}
