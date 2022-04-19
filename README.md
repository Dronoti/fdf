# Проект "FDF" (Fils De Fer, french)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![CLion](https://img.shields.io/badge/CLion-black?style=for-the-badge&logo=clion&logoColor=white)
![Mac OS](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0)
![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)

### Описание проекта
Всем привет :wave:

Данный проект в реальном времени рендерит изображение трехмерного графического каркаса («wireframe») рельефного ландшафта.
Координаты этого ландшафта (точки x, y, z) хранятся в файле с расширением ".fdf", который передается в качестве входного параметра программе.
Трехмерное представление ландшафта является важным аспектом современной картографии. Например,
сравнение различных трехмерных представлений областей высокой тектонической активности позволит лучше изучить эти явления и
их эволюцию и, как следствие, лучше подготовиться к возможной сейсмической активности.

### Демонстрация
![project demonstration](./fdf_demo.gif)

### Запуск
```bash
git clone https://github.com/Dronoti/fdf.git fdf && cd fdf && make && make clean && ./fdf ./maps/42.fdf
```

### Технология отрисовки
Для отображения трехмерной визуализации карты ландшафта был использован [алгоритм Брезенхэма.](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)

### Дополнительно
Подробная функциональность программы, ограничения и требования к ее реализации описаны в [задании.](./fdf.pdf)