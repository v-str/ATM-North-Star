#include <doctest.h>

#include <stdexcept>
#include <string>

#include <QFont>
#include <QLabel>
#include <QWidget>

#include <font_size_generator.h>

SCENARIO("font size generation") {
  GIVEN("two intances of FontSizeGenerator and QLabel") {
    QFont font;
    font.setPixelSize(14);

    QLabel label_one;
    label_one.setGeometry(10, 10, 100, 500);
    label_one.setFont(font);

    QLabel label_two;
    label_two.setGeometry(20, 20, 200, 400);
    font.setPixelSize(18);
    label_two.setFont(font);

    FontSizeGenerator(1.1, label_one);
    FontSizeGenerator font_size_generator_two(2.01, label_two);

    WHEN("method GenerateFontSize called for label_two") {
      font_size_generator_two.GenerateFontSize(&label_two);
      QFont result_font = font_size_generator_two.GetGeneratedFont();

      THEN("font pixel size should be equal earlier set") {
        REQUIRE(result_font.pixelSize() == 18);
      }
    }
  }

  GIVEN("correct instance of QWidget and FontSizeGenerator") {
    QWidget widget;
    widget.setGeometry(10, 10, 10, 10);
    QFont font;
    font.setPixelSize(14);
    widget.setFont(font);

    FontSizeGenerator font_size_generator(1.0, widget);

    WHEN("method GenerateFontSize called with null pointer") {
      std::string error_text;
      QWidget* widget_ptr = nullptr;
      try {
        font_size_generator.GenerateFontSize(widget_ptr);
      } catch (const std::exception& error) {
        error_text = error.what();
      }

      THEN("exception should contain \"Null pointer passed as parameter\"") {
        REQUIRE(error_text == std::string("Null pointer passed as parameter"));
      }
    }
  }

  GIVEN(
      "correct instance of QLabel with font = 18 pixels and "
      "FontSizeGenerator") {
    QLabel label;
    label.setGeometry(100, 100, 400, 600);
    QFont font;
    font.setPixelSize(18);
    label.setFont(font);

    FontSizeGenerator font_size_generator(2.0, label);

    WHEN(
        "method GenerateFontSize called with QLabel pointer which have equal "
        "parameters as default label") {
      label.setGeometry(100, 100, 400, 600);
      font_size_generator.GenerateFontSize(&label);

      THEN("generated font size should be equal 18") {
        label.setFont(font_size_generator.GetGeneratedFont());
        REQUIRE(label.font().pixelSize() == 18);
      }
    }

    WHEN("method GenerateFontSize called with changed QLabel instance size") {
      label.resize(750, 700);
      font_size_generator.GenerateFontSize(&label);

      THEN("generated font size should be equal 56") {
        label.setFont(font_size_generator.GetGeneratedFont());
        REQUIRE(label.font().pixelSize() == 56);
      }
    }
  }
}
