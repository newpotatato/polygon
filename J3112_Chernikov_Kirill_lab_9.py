import numpy as np

def extract_classes(time_array):
    #Находим префикс разности между массивом
    diffs=np.diff(time_array)
    #Выделяем границы подпоследовательностей
    class_starts=np.where(diffs > 1)[0]+1 
    #Костыль, чтобы у нас хорошо выделялся первая подпоследовательность
    class_starts=np.insert(class_starts, 0, 0)
    #Последним эллементом является индекс конца последней подпоследовательности (длина массива)
    class_starts=np.append(class_starts, len(time_array))
    #Cортируем по префиксу разности индексов начал классов (длинну)
    new_diffs=np.diff(class_starts)
    return max(new_diffs)

    
#Тесты
times = [1,2,5,6,7,11,64]
classes = extract_classes(times)
print(classes)
