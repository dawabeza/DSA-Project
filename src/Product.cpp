#include "../include/Product.h"

Product::Product(int p_id, std::string p_name, std::string p_cat, double p_price, int p_qty)
    : id(p_id), name(p_name), category(p_cat), price(p_price), quantity(p_qty) {
}