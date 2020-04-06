#define NUL ((char)0)
#ifndef __u_char_defined
typedef unsigned char u_char;
typedef unsigned long int u_long;
#endif
typedef __UINT_FAST32_TYPE__ word_t;

#define EXPAND_HEX(type, mask)                                                \
  ((sizeof (type) > 4) ? 0x##mask##mask : 0x##mask)
#define ZMASK(type, word)                                                     \
  ~word &(word - EXPAND_HEX (type, 01010101)) & EXPAND_HEX (type, 80808080)
#define handle_zmask(table, shft0, fst2_nonzero, shft2)                       \
  {                                                                           \
    table[d[0]] = (u_char) (zmask >> shft0) ^ 0x01;                           \
    if (fst2_nonzero)                                                         \
      table[d[1]] = 1, table[d[2]] = (u_char) (zmask >> shft2) ^ 0x01;        \
  }