#include "calculator.h"
#include "ui_calculator.h"
#include "QDebug"




calculator::calculator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);
    connect(this->ui->input, SIGNAL(textChanged()), this, SLOT(changeCaption()));

}

calculator::~calculator()
{
    delete ui;
}


void calculator::on_one_clicked()
{
    this->ui->input->insertPlainText("1");
    infix+="1";
}

void calculator::on_two_clicked()
{
     this->ui->input->insertPlainText("2");
    infix+="2";
}

void calculator::on_three_clicked()
{
     this->ui->input->insertPlainText("3");
    infix+="3";

}

void calculator::on_four_clicked()
{
     this->ui->input->insertPlainText("4");
    infix+="4";
}

void calculator::on_five_clicked()
{
     this->ui->input->insertPlainText("5");
    infix+="5";
}

void calculator::on_six_clicked()
{
     this->ui->input->insertPlainText("6");
    infix+="6";
}

void calculator::on_seven_clicked()
{
     this->ui->input->insertPlainText("7");
    infix+="7";
}

void calculator::on_eight_clicked()
{
     this->ui->input->insertPlainText("8");
    infix+="8";
}

void calculator::on_nine_clicked()
{
     this->ui->input->insertPlainText("9");
    infix+="9";
}

void calculator::on_zero_clicked()
{

     this->ui->input->insertPlainText("0");
    infix+="0";
}

void calculator::on_dot_clicked()
{


     if(!infix.isEmpty()&&
             infix.back()=='.')
       return;
     QTextCursor cur = ui->input->textCursor();
     int pos=cur.position();
    if(pos>1)
   {
       cur.setPosition(pos-2);
       cur.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor);
       if(cur.selectedText()==".")
           return;
   }


     this->ui->input->insertPlainText(".");
    infix+=".";
}

void calculator::on_add_clicked()
{
    if(infix.isEmpty()||is_character(infix.back().toLatin1()))
    {
        this->ui->input->textCursor().deletePreviousChar();
        infix.chop(1);
    }
     this->ui->input->insertPlainText("+");
    infix+="+";
}

void calculator::on_minus_clicked()
{
    if(infix.isEmpty()||is_character(infix.back().toLatin1()))
       {
        this->ui->input->textCursor().deletePreviousChar();
        infix.chop(1);
    }
     this->ui->input->insertPlainText("-");
    infix+="-";
}

void calculator::on_mul_clicked()
{
    if(infix.isEmpty()||is_character(infix.back().toLatin1()))
      {
        this->ui->input->textCursor().deletePreviousChar();
        infix.chop(1);
    }
     this->ui->input->insertPlainText("*");
    infix+="*";
}

void calculator::on_div_clicked()
{
    if(infix.isEmpty()||is_character(infix.back().toLatin1()))
    {
      this->ui->input->textCursor().deletePreviousChar();
      infix.chop(1);
  }
     this->ui->input->insertPlainText("/");
    infix+="/";
}

void calculator::on_pow_clicked()
{
   if(infix.isEmpty()||is_character(infix.back().toLatin1()))
    {
      this->ui->input->textCursor().deletePreviousChar();
      infix.chop(1);
  }
     this->ui->input->insertPlainText("^");
    infix+="^";

}

void calculator::on_p_c_clicked()
{
     this->ui->input->insertPlainText(")");
    infix+=")";
}

void calculator::on_p_o_clicked()
{
     this->ui->input->insertPlainText("(");
    infix+="(";
}

void calculator::on_back_clicked()
{
    if(infix.back()=='s'||infix.back()=='t'||infix.back()=='c')
    {
        ui->input->textCursor().deletePreviousChar();
        ui->input->textCursor().deletePreviousChar();
    }
    ui->input->textCursor().deletePreviousChar();
    infix.chop(1);
}

void calculator::on_clear_clicked()
{
    this->ui->input->clear();
    this->ui->result->clear();
    this->steps.clear();
    postfix.clear();
    infix.clear();
}

void calculator::on_tan_clicked()
{
   if(infix.isEmpty()||(infix.back()<48 || infix.back()>57))
   {
       ui->input->insertPlainText("tan(");
       infix+="t(";
   }
   else
   {
       infix.chop(1);
       infix+="t(";
       ui->input->textCursor().deletePreviousChar();
       ui->input->insertPlainText("tan(");
   }
}

void calculator::on_cos_clicked()
{
    if(infix.isEmpty()||(infix.back()<48 || infix.back()>57))
    {
        ui->input->insertPlainText("cos(");
        infix+="c(";
    }
    else
    {
        infix.chop(1);
        infix+="c(";
        ui->input->textCursor().deletePreviousChar();
        ui->input->insertPlainText("cos(");
    }

}

void calculator::on_sin_clicked()
{
    if(infix.isEmpty()||(infix.back()<48 || infix.back()>57))
    {
        ui->input->insertPlainText("sin(");
        infix+="s(";
    }
    else
    {
        infix.chop(1);
        infix+="s(";
        ui->input->textCursor().deletePreviousChar();
        ui->input->insertPlainText("sin(");
    }
}
bool calculator::is_character(char x)
{

    switch (x)
    {
    case '+':
    case '-':
    case '*':
    case '^':
    case '/':return true;break;
    default:return false;

    }
}

bool calculator::Error_control(QString p)
{

    linked_stack<QString> stack;
    int size=p.size();
    QString a="*^/";
    QString b=")(";
    QString c="+-";
    for(int i=0;i<size;i++)
    {
        if(p[i]=='(')
        {
            if(p[i+1]==')')
                return false;
           stack.push(QString(QChar('(')));
        }
         else if(a.contains(p[i]))
        {
            if(i==0)
                return false;
            if(i==size-1)
                return false;
            if(p[i]=='/'&& p[i+1]=='0')
                return false;
            if(b.contains(p[i-1]) && p[i-1]=='(')
                return false;
            if(b.contains(p[i+1]) && p[i+1]==')')
                return false;

        }
        else if(c.contains(p[i]) && i>0)
        {
            if(i==size-1)
                return false;
            if(p[i-1]==')' && p[i+1]==')')
                return false;
            if( i==size-1&& p[i+1]==')')
                return false;

        }
        else if(p[i]==')')
        {
            if(stack.is_empty())
                return false;
            stack.pop();
        }

    }
   if(!stack.is_empty())
        return false;
    return true;

}

int calculator::precedence(QString x)
{
    char y=x.at(0).toLatin1();
    switch (y)
    {
       case 't':
       case 's':
       case 'c':return 4;break;
       case '^':
       case '_':return 3;break;
       case '*':
       case '/':return 2;break;
       case '+':
       case '-':return 1;break;
    default:return 0;

    }
}

QString calculator::in_to_post(QString p)
{
    linked_stack<QString> st;
    int size=p.size();
    QString post="";
    QString a="+-/^*tsc";

    try
    {
        for(int i=0;i<size;i++)
        {
            if(p[i]=='(')
            st.push(QString(QChar('(')));

            else if (p[i]==')')
            {
                if(st.is_empty())
                throw "";

                QString x;
                while ((x=st.pop())!='(')
                {
                    post+=" ";
                    post+=x;
                    if(st.is_empty())
                        throw "";

                }
            }
            else if(p[i]=='+'&& (i==0||p[i-1]=='('))
            {

            }
            else if(a.contains(p[i]))
            {
                if(!post.isEmpty()&&post.back()!=' ')
                post+=" ";
                if(p[i]=='-'&& (i==0||p[i-1]=='('))
                   p[i]='_';
                int prec=precedence(QString(QChar(p[i])));

                if(st.is_empty()||precedence(st.top())<prec)
                st.push(QString(QChar(p[i])));
               else if(p[i]=='^')
                {
                    QString x;
                    while (!st.is_empty()&&precedence(x=st.top())>prec)
                    {            
                        post+=x;
                         post+=" ";
                         if(st.is_empty())
                             throw "";
                         st.pop();
                    }
                    st.push(QString(QChar(p[i])));
                }
                else
                {
                    QString x;
                    while (!st.is_empty()&&precedence(x=st.top())>=prec)
                    {
                        post+=x;
                         post+=" ";
                         if(st.is_empty())
                             throw "";
                         st.pop();
                    }
                    st.push(QString(QChar(p[i])));
                }

            }
            else
            post+=p[i];
        }
        while (!st.is_empty())
        {
            post+=" ";
            post+=st.pop();
        }

    }
    catch (...)
    {
         this->ui->result->setText("Eror");
    }
    return post;

}
QString calculator::post_to_in(QString x)
{
    QString a="+-^*/";
    QString b="_tsc";
    linked_stack<QString> st;
    QStringList qsl;
    qsl=x.split(" ");
    for(QString value:qsl)
    {
        if(a.contains(value))
        {
           QString val1=st.pop();
           QString val2=st.pop();
           st.push("("+val2+value+val1+")");

        }
        else if(b.contains(value))
        {
            char y=value.at(0).toLatin1();
            switch (y)
            {
               case '_':
            {
                QString val1=st.pop();
                st.push("(-"+val1+")");
                break;
            }
                case 't' :
            {
                QString val1=st.pop();
                st.push("tan("+val1+")");
                break;
            }
                case 's':
            {
                QString val1=st.pop();
                st.push("sin("+val1+")");
                break;
            }
               case 'c':
            {
                QString val1=st.pop();
                st.push("cos("+val1+")");
                break;
            }


            }
        }

        else
            st.push(QString::number(value.toDouble(),'g',15));
    }
    return st.pop();

}
QString calculator::evaluate(QString x,QList<QString>* steps, QList<QString>* history)
{
    QString a="+-_^*/stc";
    linked_stack<QString> st;
    QString infix=post_to_in(x);
    steps->append(infix);
    QStringList qsl;
    qsl=x.split(" ");
      try
      {
          for(QString value:qsl)
          {
                 if(a.contains(value))
                  {
                     double val1=st.pop().toDouble();
                     char y=value.at(0).toLatin1();


                     switch (y)
                     {
                       case'+':
                     {
                          double val2=st.pop().toDouble();
                         QString result=QString::number(val2+val1,'g',15);
                         st.push(result);
                         QString s="("+QString::number(val2,'g',15)+"+"+QString::number(val1,'g',15)+")";
                         infix.replace(infix.indexOf(s),s.size(),result);
                         steps->append(infix);
                         break;
                     }
                       case'-':
                     {
                          double val2=st.pop().toDouble();
                         QString result=QString::number(val2-val1,'g',15);
                         st.push(result);
                         QString s="("+QString::number(val2,'g',15)+"-"+QString::number(val1,'g',15)+")";
                         infix.replace(infix.indexOf(s),s.size(),result);
                         steps->append(infix);
                         break;
                     }
                       case'*':
                     {
                          double val2=st.pop().toDouble();
                         QString result=QString::number(val2*val1,'g',15);
                         st.push(result);
                         QString s="("+QString::number(val2,'g',15)+"*"+QString::number(val1,'g',15)+")";
                         infix.replace(infix.indexOf(s),s.size(),result);
                         steps->append(infix);
                         break;

                     }
                       case'/':
                     {
                          double val2=st.pop().toDouble();
                         QString result=QString::number(val2/val1,'g',15);
                         st.push(result);
                         QString s="("+QString::number(val2,'g',15)+"/"+QString::number(val1,'g',15)+")";
                         infix.replace(infix.indexOf(s),s.size(),result);
                         steps->append(infix);
                         break;
                     }
                       case'^':
                     {
                          double val2=st.pop().toDouble();
                         QString result=QString::number(pow(val2,val1),'g',15);
                         st.push(result);
                         QString s="("+QString::number(val2,'g',15)+"^"+QString::number(val1,'g',15)+")";
                         infix.replace(infix.indexOf(s),s.size(),result);
                         steps->append(infix);
                         break;
                     }
                       case'_':
                     {

                         st.push(QString::number(val1*-1));
                         QString s="(-"+QString::number(val1,'g',15)+")";
                         infix.replace(infix.indexOf(s),s.size(),QString::number(val1*-1));
                         steps->append("no"+infix);
                         break;


                     }
                     case 't':
                     {

                        double r=(val1/180)+0.5;
                         if(r==int(r))
                         {
                             steps->clear();
                             ui->result->clear();
                             postfix.clear();
                           return "Eror!";
                         }

                         QString result=QString::number(tan(val1*(M_PI/180.0)),'g',15);
                         st.push(result);
                         QString s="tan("+QString::number(val1,'g',15)+")";
                         infix.replace(infix.indexOf(s),s.size(),result);
                         steps->append(infix);
                         break;

                     }
                     case 's':
                     {

                         QString result;
                        double r=val1/180;
                         if(r==int(r))
                             result="0";

                         else
                         result=QString::number(sin(val1*(M_PI/180.0)),'g',15);
                         st.push(result);
                         QString s="sin("+QString::number(val1,'g',15)+")";
                         infix.replace(infix.indexOf(s),s.size(),result);
                         steps->append(infix);
                         break;

                     }
                     case 'c':
                     {

                         QString result;
                        double r=(val1/180)+0.5;
                         if(r==int(r))
                             result="0";

                         else
                         result=QString::number(cos(val1*(M_PI/180.0)),'g',15);
                         st.push(result);
                         QString s="cos("+QString::number(val1,'g',15)+")";
                         infix.replace(infix.indexOf(s),s.size(),result);
                         steps->append(infix);
                         break;

                     }

                     }

                  }
                  else
                      st.push(value);
          }
      }

      catch (...)
      {
          this->ui->result->setText("Eror");
      }
      if(st.size()>1)
            this->ui->result->setText("Eror");
      history->append(ui->input->toPlainText());
      history->append("="+st.top()+"\n");
      return st.top() ;

}



void calculator::on_equal_clicked()
{
    if(infix.isEmpty())
        return;
    if(Error_control(infix))
    {
        postfix=in_to_post(infix);

       this->ui->result->setText("=");
        ui->result->insert(evaluate(postfix,&steps,&history));

    }
    else
         this->ui->result->setText("Eror");
}

void calculator::on_history_clicked()
{
     ui->input->clear();
     ui->result->clear();
     for(QString value:history)
         ui->textEdit->append(value);
}

void calculator::on_step_clicked()
{


    int i=1;
    for(QString value:steps)
    {
        if(value.contains("no"))
            continue;
        ui->textEdit->setTextColor(QColor::fromRgb(255, 165, 0));
        ui->textEdit->append("step"+QString::number(i)+":");
        ui->textEdit->setTextColor(Qt::white);
        ui->textEdit->append(value);
        i++;
    }
    steps.clear();


}

void calculator::changeCaption()
{

    this->ui->result->clear();
    steps.clear();
    ui->textEdit->clear();
    postfix.clear();
}

void calculator::on_tree_clicked()
{
    if(postfix=="")
        return;
    if(ui->textEdit->toPlainText().contains("order"))
        return;
    Binary_Tree tree;
    tree.post_to_tree(&postfix);
    ui->textEdit->setTextColor(QColor::fromRgb(255, 165, 0));
    ui->textEdit->append("\ninorder:");
     ui->textEdit->setTextColor(Qt::white);
    ui->textEdit->insertPlainText(tree.inorder);

    ui->textEdit->setTextColor(QColor::fromRgb(255, 165, 0));
    ui->textEdit->append("postorder:");
     ui->textEdit->setTextColor(Qt::white);
    ui->textEdit->insertPlainText(tree.postorder);

    ui->textEdit->setTextColor(QColor::fromRgb(255, 165, 0));
    ui->textEdit->append("preorder:");
     ui->textEdit->setTextColor(Qt::white);
    ui->textEdit->insertPlainText(tree.preorder);

    ui->textEdit->setTextColor(QColor::fromRgb(255, 165, 0));
    ui->textEdit->append("level_order:");
     ui->textEdit->setTextColor(Qt::white);
    ui->textEdit->insertPlainText(tree.level_order);
    ui->textEdit->append("");



}





