#include <include/field.h>

Field::Field(i16 _n, i16 _m)
{
    height = _n;
    width = _m;
    cells.resize(_n);
    for(u16 i = 0; i < cells.size(); ++i){
        cells[i].resize(_m);
        for(u16 j = 0; j < cells[i].size(); ++j){
            Coords coords(j, i);
            cells[i][j] = new Cell(this, coords);
        }
    }
}

Field::~Field()
{

}

void Field::Tick()
{
    for(u16 i = 0; i < cells.size(); ++i){
        for(u16 j = 0; j < cells[i].size(); ++j){
            cells[i][j]->Tick();
        }
    }
}

void Field::Render()
{
    std::cout << "==================BEGIN FIELD==================\n";
    for(u16 i = 0; i < cells.size(); ++i){
        for(u16 j = 0; j < cells[i].size(); ++j){
            cells[i][j]->Render();
        }
        std::cout << "\n";
    }
    std::cout << "==================END FIELD==================\n";
}

Cell* Field::GetCellByCoords(Coords coords)
{
    coords.x = (coords.x + width) % width;
    coords.y = (coords.y + height) % height;
    return cells[coords.y][coords.x];
}
