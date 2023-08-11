/**
 * @brief It implements the LIBSCREEN module
 * @file libscreen.h
*/

#ifndef LIBSCREEN_H_

/**
 * @brief Area structure
*/
typedef struct _Area Area;

/**
 * @brief It creates a new screen area
 * 
 * @param rows the number of rows
 * @param column the number of columns
 * @return no return
*/
void screen_init(int rows, int columns);

/**
 * @brief It destroys the sreen area
 * 
 * @return no return
*/
void screen_destroy();

/**
 * @brief It paints the current screen position
 * 
 * @return no return
*/
void screen_paint();

/**
 * @brief It creates a new area in a screen
 * 
 * @param x the x-coordinate of the up-left corner of the area
 * @param y the y-coordinate of the up-left corner of the area
 * @param width the width of the area
 * @param height the height of the area
 * @return a pointer to an Area
*/
Area *screen_area_init(int x, int y, int width, int height);

/**
 * @brief It destroys an area
 * 
 * @param area a pointer to the area
 * @return no return
*/
void screen_area_destroy(Area *area);

/**
  * @brief It cleares an area, eraising all its content
  * 
  * @param area a pointer to the area
  * @return no return
  */
void  screen_area_clear(Area* area);

/**
  * @brief It resets the cursor of an area
  * 
  * @param area a pointer to the area
  * @return no return
  */
void  screen_area_reset_cursor(Area* area);

/**
  * @brief It introduces some information inside an area
  * 
  * @param area a pointer to the area
  * @param str a string with information
  */
void  screen_area_puts(Area* area, char *str);

#endif /*LIBSCREEN_H_*/