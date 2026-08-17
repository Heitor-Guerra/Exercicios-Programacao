#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Sample Qt App");
    window.resize(1200, 600);

    QVBoxLayout* layout = new QVBoxLayout(&window);

    QLineEdit* textBox = new QLineEdit();
    textBox->setPlaceholderText("Type something here...");
    
    QLabel* label = new QLabel();
    label->setText("Oi");
    
    QPushButton* button = new QPushButton("Show Text");
    
    // Connect button click to show message
    QObject::connect(button, &QPushButton::clicked, [&]() {
        QMessageBox::information(&window, "Input", 
            QString("You typed: %1").arg(textBox->text()));
    });

    layout->addWidget(textBox);
    layout->addWidget(label);
    layout->addWidget(button);

    window.show();
    return app.exec();
}
