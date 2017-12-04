#include <doctest.h>

#include <QFont>
#include <QSize>

#include <font_size_calculator.h>
#include <initial_widget_data.h>

SCENARIO("font size calculation") {
  GIVEN("instances of InitialWidgetData") {
    QFont font;
    font.setPixelSize(16);

    InitialWidgetData initial_widget_data;
    initial_widget_data.SetFontScaleMultiplier(0.8);
    initial_widget_data.SetInitialWidgetFont(font);
    initial_widget_data.SetInitialWidgetWidth(600);
    initial_widget_data.SetInitialWidgetHeight(400);

    WHEN(
        "current size increased more in width, than on height "
        "and method CalculateCurrentFontSize of FontSizeCalculator called") {
      QSize current_size;
      current_size.setWidth(800);
      current_size.setHeight(550);

      FontSizeCalculator font_size_calculator;
      int result_font_size = font_size_calculator.CalculateCurrentFontSize(
          current_size, initial_widget_data);

      THEN("result font size should be equal 25") {
        REQUIRE(result_font_size == 25);
      }
    }

    WHEN(
        "current size increased more in height, than on width "
        "and method CalculateCurrentFontSize of FontSizeCalculator called") {
      QSize current_size;
      current_size.setWidth(700);
      current_size.setHeight(900);

      FontSizeCalculator font_size_calculator;
      int result_font_size = font_size_calculator.CalculateCurrentFontSize(
          current_size, initial_widget_data);

      THEN("result font size should be equal 40") {
        REQUIRE(result_font_size == 40);
      }
    }

    WHEN(
        "current size width less than initial width "
        "and method CalculateCurrentFontSize of FontSizeCalculator called") {
      QSize current_size;
      current_size.setWidth(500);
      current_size.setHeight(650);

      FontSizeCalculator font_size_calculator;
      int result_font_size = font_size_calculator.CalculateCurrentFontSize(
          current_size, initial_widget_data);

      THEN("result font size should be equal initial font size") {
        REQUIRE(result_font_size == 16);
      }
    }

    WHEN(
        "current size height less than initial height "
        "and method CalculateCurrentFontSize of FontSizeCalculator called") {
      QSize current_size;
      current_size.setWidth(650);
      current_size.setHeight(350);

      FontSizeCalculator font_size_calculator;
      int result_font_size = font_size_calculator.CalculateCurrentFontSize(
          current_size, initial_widget_data);

      THEN("result font size should be equal initial font size") {
        REQUIRE(result_font_size == 16);
      }
    }
  }
}
