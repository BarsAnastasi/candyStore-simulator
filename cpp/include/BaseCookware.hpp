#pragma once
#include <string>
#include <iostream>
#include <memory>

class Ingredient; // Предварительное объявление

class BaseCookware {
private:
    std::string m_name;
    bool m_isBusy;
    int m_timer; // оставшееся время в секундах
    std::weak_ptr<Ingredient> m_currentIngredient; // с чем сейчас работает

protected:
    // Метод нужен наследникам, но не снаружи
    void StartWork(std::shared_ptr<Ingredient> ing, int time);

public:
    BaseCookware(std::string name);
    virtual ~BaseCookware();

    // Чисто виртуальный метод (реализация в наследниках)
    virtual void Process() = 0;

    void Release();

    // Геттеры
    std::string GetName() const { return m_name; }
    bool IsBusy() const { return m_isBusy; }
    int GetTimer() const { return m_timer; }

    // Сеттеры
    void SetName(const std::string& name);
    void SetBusy(bool busy);
    void SetTimer(int time);
    void SetIngredient(std::shared_ptr<Ingredient> ing);

    virtual std::string Describe() const;

    // Статический член
    inline static int s_totalCount = 0;
    static int GetTotalCount() { return s_totalCount; }
};