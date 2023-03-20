class HouseScheme:
    def __init__(self, rooms_count, square, comb_bath) -> None:
        if type(rooms_count) == int and type(square) == int and square >= 0 and type(comb_bath) == bool:
            self.rooms_count = rooms_count
            self.square = square
            self.combination_bathroom = comb_bath
        else:
            raise(ValueError('Invalid value'))

class CountryHouse(HouseScheme):
    def __init__(self, rooms_count, square, comb_bath, floors_count, plot_area) -> None:
        super().__init__(rooms_count, square, comb_bath)
        if type(floors_count) == int and type(plot_area) == int:
            self.floors_count = floors_count
            self.plot_area = plot_area
        else:
            raise(ValueError('Invalid value'))

    def __str__(self) -> str:
        return f'Country House: Количество жилых комнат {self.rooms_count}, Жилая площадь {self.square}, Совмещенный санузел {self.combination_bathroom}, Количество этажей {self.floors_count}, Площадь участка {self.plot_area}.'

    def __eq__(self, house) -> bool:
        if isinstance(house, CountryHouse):
            if self.square == house.square and self.plot_area == house.plot_area and abs(self.floors_count - house.floors_count) <= 1:
                return True
            else:
                return False
        # Add else: return False if it necessary

class Apartment(HouseScheme):
    def __init__(self, rooms_count, square, comb_bath, floor, windows_side) -> None:
        super().__init__(rooms_count, square, comb_bath)
        if type(floor) == int and 1 <= floor <= 15 and windows_side in ['N', 'S', 'W', 'E']:
            self.floor = floor
            self.windows_side = windows_side
        else:
            raise(ValueError('Invalid value'))
    
    def __str__(self) -> str:
        return f'Apartment: Количество жилых комнат {self.rooms_count}, Жилая площадь {self.square}, Совмещенный санузел {self.combination_bathroom}, Этаж {self.floor}, Окна выходят на {self.windows_side}.'

class CountryHouseList(list):
    def __init__(self, name):
        super().__init__()
        self.name = name
    
    def append(self, p_object) -> None:
        if isinstance(p_object, CountryHouse):
            super().append(p_object)
        else:
            raise(TypeError(f'Invalid type {type(p_object)}'))
    
    def total_square(self):
        total_square = 0
        for house in self:
            total_square += house.square
        return total_square

class ApartmentList(list):
    def __init__(self, name):
        super().__init__()
        self.name = name
    
    def extend(self, __iterable) -> None:
        super().extend(list(filter(lambda obj: isinstance(obj, Apartment), __iterable)))

    def floor_view(self, floors, directions) -> str:
        out_floors = list(filter(lambda obj: floors[0] <= obj.floor <= floors[1], self))
        for some_floor in out_floors:
            if some_floor.windows_side in directions:
                print(f'{some_floor.windows_side}: {some_floor.floor}')
