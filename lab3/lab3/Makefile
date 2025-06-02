# Укажите здесь директорию с исходными файлами (.cpp)
SOURCE_DIR = source

# Укажите здесь имя исполняемого файла
EXECUTABLE = main_reviewed

# Укажите здесь флаги компиляции
CXXFLAGS = -std=c++20 -g2 -Wall -Wextra -Werror -Wpedantic

# Укажите здесь флаги компоновщика
LDFLAGS =

# Получаем список исходных файлов (.cpp) в директории SOURCE_DIR
SOURCE_FILES = main.cpp $(wildcard $(SOURCE_DIR)/*.cpp)

# Правило для сборки исполняемого файла
$(EXECUTABLE): $(SOURCE_FILES)
	clang++ $(CXXFLAGS) $(SOURCE_FILES) $(LDFLAGS) -o $(EXECUTABLE)

# Правило для очистки проекта
clean:
	rm -f $(EXECUTABLE)

# Правило для запуска исполняемого файла
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Правило для запуска статического анализа
analyze:
	clang-tidy $(SOURCE_FILES) -- $(CXXFLAGS)

.PHONY: clean run analyze
