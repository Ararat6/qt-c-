#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
//#include <QSize>
#include <QSpinBox>
#include <QSlider>

int main(int argc, char** argv)
{
	QApplication app(argc,argv);
	QWidget* w = new QWidget();
	
	QPushButton* button1 = new QPushButton("One");
	QPushButton* button2 = new QPushButton("Two");
	QPushButton* button3 = new QPushButton("Three");
	QPushButton* button4 = new QPushButton("Four");

	QHBoxLayout* h = new QHBoxLayout();
	h->addWidget(button1);
	h->addWidget(button2);

	QVBoxLayout* v = new QVBoxLayout();
	v->addWidget(button3);
	v->addWidget(button4);

	h->addLayout(v);

	QSpinBox* spbox = new QSpinBox();
	spbox->setRange(0, 100);
	spbox->setValue(25);

	QSlider* sdr = new QSlider();
	sdr->setRange(0, 100);
	sdr->setValue(15);
	QSlider* sdr1 = new QSlider(Qt::Horizontal);
	sdr1->setRange(0, 100);
	sdr1->setValue(75);
	
	QHBoxLayout* h2 = new QHBoxLayout();
	h2->addWidget(sdr);
	h2->addWidget(sdr1);
	
	QObject::connect(spbox, SIGNAL(valueChanged(int)), sdr, SLOT(setValue(int)));
	QObject::connect(spbox, SIGNAL(valueChanged(int)), sdr1, SLOT(setValue(int)));
	QObject::connect(sdr, SIGNAL(valueChanged(int)), sdr1, SLOT(setValue(int)));
	QObject::connect(sdr, SIGNAL(valueChanged(int)), spbox, SLOT(setValue(int)));
	QObject::connect(sdr1, SIGNAL(valueChanged(int)), sdr, SLOT(setValue(int)));
	QObject::connect(sdr1, SIGNAL(valueChanged(int)), spbox, SLOT(setValue(int)));
	
	QVBoxLayout* lay = new QVBoxLayout();
	lay->addLayout(h);
	lay->addWidget(spbox);
	lay->addLayout(h2);

	w->setLayout(lay);
	//w->setMinimumSize(400, 400);
	w->show();
	
	return app.exec();
}
