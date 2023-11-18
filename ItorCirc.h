#ifndef ItorCirc_UTILS_H_
#define ItorCirc_UTILS_H_


template<class T>
class ItorCirc {
    using T_iterator = typename T::iterator;
    using T_value_type = typename T::iterator::value_type;
public:
    ItorCirc(T& data) :data_wrappered(data) { itor = data.begin(); }
    ItorCirc(T& data, T_iterator& itor_default) :data_wrappered(data), itor(itor_default) { }
    void fetch_add() {
        if (isChanged) { isChanged = false; }
        else { itor++; }
    }
    void fetch_minus() {
        if (isChanged) { isChanged = false; }
        else { itor--; }
    }
    void erase(T_iterator itor_to_erase) {
        itor = data_wrappered.erase(itor_to_erase);
        isChanged = true;
    }
    void erase_current() {
        itor = data_wrappered.erase(itor);
        isChanged = true;
    }
    void force_change_index(T_iterator itor_new) {
        itor = itor_new;
        isChanged = true;
    }
    bool isEnd() {
        return itor == data_wrappered.end();
    }
    T_iterator get_Iterator() {
        return itor;
    }


private:
    T& data_wrappered;
    T_iterator itor;
    bool isChanged = false;
};


    

#endif  // ItorCirc_UTILS_H_

