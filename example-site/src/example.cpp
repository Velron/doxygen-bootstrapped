/**
 * @file example.cpp
 *
 * example file, inspired from
 * https://www.star.bnl.gov/public/comp/sofi/doxygen/docblocks.html
 */

/**
 * @brief A test class.
 *
 * A more elaborate class description.
 *
 * @todo add some functionality
 */
class Test {
 public:

  /**
   * @brief An enum.
   *
   * More detailed enum description.
   */
  enum TEnum {
    TVal1,     /**< enum value TVal1. */
    TVal2,     /**< enum value TVal2. */
    TVal3      /**< enum value TVal3. */
  } * enumPtr, /**< enum pointer. Details. */
      enumVar; /**< enum variable. Details. */

  /**
   * @brief A constructor.
   *
   * A more elaborate description of the constructor.
   */
  Test();

  /**
   * @brief A destructor.
   *
   * A more elaborate description of the destructor.
   * @warning beware of destruction!
   */
  ~Test();

  /**
   * @brief a normal member taking two arguments and returning an integer value.
   * @param a an integer argument.
   * @param s a constant character pointer.
   * @see Test()
   * @see ~Test()
   * @see testMeToo()
   * @see publicVar()
   * @return The test results
   */
  int testMe(int a, const char *s);

  /**
   * @brief A pure virtual member.
   * @see testMe()
   * @param c1 the first argument.
   * @param c2 the second argument.
   */
  virtual void testMeToo(char c1, char c2) = 0;

  /**
   * @brief a public variable.
   *
   * Details.
   *
   * @note A small note.
   */
  int publicVar;

  /**
   * @brief a function variable.
   *
   * Details.
   */
  int (*handler)(int a, int b);
};
