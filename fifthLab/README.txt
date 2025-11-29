Проект: pmr_stack_project
Реализация:
- VectorMemoryResource (fixed buffer, bookkeeping in std::vector) — include/my_memory_resource.h + src/my_memory_resource.cpp
- Stack<T> — include/stack.h + include/stack.ipp (использует std::pmr::polymorphic_allocator<T>)
- main.cpp — демонстрация работы с Foo и int

Файловая структура в проекте:
- include/
    - my_memory_resource.h
    - stack.h
    - stack.ipp
- src/
    - my_memory_resource.cpp
    - main.cpp
- CMakeLists.txt

Примечание: в репозитории также сохранено изображение варианта задания (путь к файлу в среде): /mnt/data/7a05eeb0-b4a6-4542-9127-29e55633cf39.png
