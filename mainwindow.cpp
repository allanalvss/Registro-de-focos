#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/pic/ids.jpeg");
    ui->lab_print->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarEstatisticas()
{
    QString maior="red";
    QString menor="green";
    ui->lbl_avg->setText(QString::number(jp.media_de_focos(),'f',2));
    ui->lbl_highest->setText(QString(jp.maior_risco()));
    ui->lbl_lowest->setText(QString(jp.menor_risco()));
    ui->lbl_highest->setStyleSheet("color: "+maior);
    ui->lbl_lowest->setStyleSheet("color: "+menor);
}

void MainWindow::insert_cadastro(local loc, int row)
{
        ui->tbl_data->setItem(row,0,new QTableWidgetItem(loc.getbairro()));
        ui->tbl_data->setItem(row,1,new QTableWidgetItem(QString::number(loc.getquantidade())));
        QTableWidgetItem *risco=new QTableWidgetItem(loc.getrisco());
        if(loc.getrisco()=="Alto"){
        risco->setTextColor("red");
        }
        if(loc.getrisco()=="Médio"){
        risco->setTextColor("blue");
        }
        if(loc.getrisco()=="Baixo"){
        risco->setTextColor("green");
        }
        ui->tbl_data->setItem(row,2,risco);
    }




void MainWindow::on_ins_button_clicked()
{
    int qnt_row = ui->tbl_data->rowCount();

    if(ui->name_bar->text().size() != 0 && ui->quant_bar->text().size() != 0){
        bairros = new local();

        bairros->setbairro(ui->name_bar->text());
        bairros->setquantidade(ui->quant_bar->text().toInt());

        ui->tbl_data->insertRow(qnt_row);
        QTableWidgetItem *risco=new QTableWidgetItem(bairros->getrisco());
        if(bairros->getrisco()=="Alto"){
        risco->setTextColor("red");
        }
        if(bairros->getrisco()=="Médio"){
        risco->setTextColor("blue");
        }
        if(bairros->getrisco()=="Baixo"){
        risco->setTextColor("green");
        }
        ui->tbl_data->setItem(qnt_row,0,new QTableWidgetItem(bairros->getbairro()));
        ui->tbl_data->setItem(qnt_row,1,new QTableWidgetItem(QString::number(bairros->getquantidade())));
        ui->tbl_data->setItem(qnt_row,2,risco);

        ui->name_bar->clear();
        ui->quant_bar->clear();

        jp.inserirbairro(*bairros);
        atualizarEstatisticas();
        delete bairros;
    }
}


void MainWindow::on_ord_button_clicked()
{
    jp.ordernarname();
        ui->tbl_data->clearContents();
        int qnt_row = ui->tbl_data->rowCount();


        for(int i=0;i<qnt_row;i++){
            ui->tbl_data->setItem(i,0,new QTableWidgetItem(jp.getloc(i).getbairro()));
            ui->tbl_data->setItem(i,1,new QTableWidgetItem(QString::number(jp.getloc(i).getquantidade())));
            QTableWidgetItem *risco=new QTableWidgetItem(jp.getloc(i).getrisco());
            if(jp.getloc(i).getrisco()=="Alto"){
            risco->setTextColor("red");
            }
            if(jp.getloc(i).getrisco()=="Médio"){
            risco->setTextColor("blue");
            }
            if(jp.getloc(i).getrisco()=="Baixo"){
            risco->setTextColor("green");
            }
            ui->tbl_data->setItem(i,2,risco);
        }


}

void MainWindow::on_ord2_button_clicked()
{
    jp.ordenar_quantidade();
    int qnt_row = ui->tbl_data->rowCount();


    for(int i=0;i<qnt_row;i++){
        ui->tbl_data->setItem(i,0,new QTableWidgetItem(jp.getloc(i).getbairro()));
        ui->tbl_data->setItem(i,1,new QTableWidgetItem(QString::number(jp.getloc(i).getquantidade())));
        QTableWidgetItem *risco=new QTableWidgetItem(jp.getloc(i).getrisco());
        if(jp.getloc(i).getrisco()=="Alto"){
        risco->setTextColor("red");
        }
        if(jp.getloc(i).getrisco()=="Médio"){
        risco->setTextColor("blue");
        }
        if(jp.getloc(i).getrisco()=="Baixo"){
        risco->setTextColor("green");
        }
        ui->tbl_data->setItem(i,2,risco);
    }
}

void MainWindow::on_actionSalvar_triggered()
{

    QString name_arq=QFileDialog::getSaveFileName(this,"Lista de focos","","Texto Puro(*.txt)");
    if(gerador::salvar_cadastro(name_arq,jp)){
        QMessageBox::information(this,"Salvar cadastro","Os dados foram salvos com sucesso!");
    }
    else{
        QMessageBox::information(this,"Salvar cadastro","Não foi possível salvar os dados");
    }

}



void MainWindow::on_actionCarregar_dados_triggered()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Cadastro","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");

        if(gerador::carregar_cadastro(nomeArquivo,jp)){

            ui->tbl_data->clearContents();
            for(int i=0;i<jp.size();i++){

                if(i >= ui->tbl_data->rowCount())
                    ui->tbl_data->insertRow(i);

                insert_cadastro(jp[i],i);
                  QMessageBox::information(this, "Carregar cadastro","Dados carregados com sucesso!");
            }

        }else{
            QMessageBox::information(this, "Carregar cadastro","Não foi possível carregar os dados");
        }
        atualizarEstatisticas();

}





void MainWindow::on_tbl_data_cellDoubleClicked(int row, int column)
{
  if(column==0){
  int qnt_row = ui->tbl_data->rowCount();
  QString nome=QInputDialog::getText(this,"Editar","Qual o novo bairro? ", QLineEdit::Normal);
  jp.EditBairro(row,nome);
  ui->tbl_data->clearContents();
  for(int i=0;i<qnt_row;i++){
    ui->tbl_data->setItem(i,column,new QTableWidgetItem(jp[i].getbairro()));
    ui->tbl_data->setItem(i,1,new QTableWidgetItem(QString::number(jp[i].getquantidade())));
    QTableWidgetItem *risco=new QTableWidgetItem(jp[i].getrisco());
    if(jp[i].getrisco()=="Alto"){
    risco->setTextColor("red");
    }
    if(jp[i].getrisco()=="Médio"){
    risco->setTextColor("blue");
    }
    if(jp[i].getrisco()=="Baixo"){
    risco->setTextColor("green");
    }
    ui->tbl_data->setItem(i,2,risco);
  }
    atualizarEstatisticas();
    QMessageBox::information(this,"Editar","Dados alterados!");
}
  else if(column==1){
      int qnt_row = ui->tbl_data->rowCount();
      QString numero=QInputDialog::getText(this,"Editar","Qual o numero atual de focos?", QLineEdit::Normal);
      jp.EditQuants(row,numero.toInt());
      ui->tbl_data->clearContents();
      for(int i=0;i<qnt_row;i++){
        ui->tbl_data->setItem(i,0,new QTableWidgetItem(jp[i].getbairro()));
        ui->tbl_data->setItem(i,1,new QTableWidgetItem(QString::number(jp[i].getquantidade())));
        QTableWidgetItem *risco=new QTableWidgetItem(jp[i].getrisco());
        if(jp[i].getrisco()=="Alto"){
        risco->setTextColor("red");
        }
        if(jp[i].getrisco()=="Médio"){
        risco->setTextColor("blue");
        }
        if(jp[i].getrisco()=="Baixo"){
        risco->setTextColor("green");
        }
        ui->tbl_data->setItem(i,2,risco);
      }
        atualizarEstatisticas();
        QMessageBox::information(this,"Editar","Dados alterados!");
    }
  }


void MainWindow::on_reset_button_clicked()
{
    int qnt_row = ui->tbl_data->rowCount();
    for(int i=0;i<qnt_row;i++){
    ui->tbl_data->removeRow(i);
    }
    atualizarEstatisticas();
}
