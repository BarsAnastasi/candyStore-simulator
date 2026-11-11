#include "BaseCookware.hpp"

BaseCookware::BaseCookware(std::string name)
    : m_name(std::move(name)), m_isBusy(false), m_timer(0) {
    std::cout << "Оборудование \"" << m_name << "\" готово к работе.\n";
    s_totalCount++;
}

BaseCookware::~BaseCookware() {
    std::cout << "Оборудование \"" << m_name << "\" уничтожено.\n";
}

void BaseCookware::StartWork(std::shared_ptr<Ingredient> ing, int time) {
    m_isBusy = true;
    m_timer = time;
    m_currentIngredient = ing;
    std::cout << "[" << m_name << "] Начало работы. Таймер: " << m_timer << " сек.\n";
}

// Освобождение ресурса
void BaseCookware::Release() {
    if (m_isBusy) {
        std::cout << m_name << ": работа завершена. Ингредиент отправлен на дальнейшие шаги.\n";
        m_isBusy = false;
        m_timer = 0;
        m_currentIngredient.reset();
    }
    else {
        std::cout << m_name << ": уже свободно.\n";
    }
}

// Сеттеры
void BaseCookware::SetName(const std::string& name) {
    m_name = name;
}

void BaseCookware::SetBusy(bool busy) {
    m_isBusy = busy;
}

void BaseCookware::SetTimer(int time) {
    if (time >= 0) m_timer = time;
    else std::cout << "Error! Таймер не может быть отрицательным.\n";
}

void BaseCookware::SetIngredient(std::shared_ptr<Ingredient> ing) {
    m_currentIngredient = ing;
}

std::string BaseCookware::Describe() const {
    return m_name + (m_isBusy ? " [занято]" : " [свободно]");
}