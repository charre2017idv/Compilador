using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;
using System.Reflection;
using System.Resources;
using System.Diagnostics;
using System.Management;
using System.Windows.Forms;


namespace CompilerUI
{

  public partial class Form1 : Form
  {
    String DLLFullPath;
    dynamic compilerDLLInstance;
    bool isDLLLoaded;
    bool currentAssemblyisDebug;
    bool currentAssemblyIsx64;

    bool currentAssemblyisRelease;
    List<String> Words = new List<String>();
    List<String> LSymbols = new List<String>();
    List<String> WordsErr = new List<String>();
    List<String> ErrorsOpen = new List<String>();

    private void errorTok()
    {
      ErrorsOpen.Add("{");
      ErrorsOpen.Add("/*");
      ErrorsOpen.Add("[");
      ErrorsOpen.Add("(");
    }

    String str;
    String ErrSrc;
    String lexem;
    String type;

    public Form1()
    {
      isDLLLoaded = false;
      currentAssemblyisDebug = true;
      currentAssemblyisRelease = false;
      currentAssemblyIsx64 = true;

      InitializeComponent();
    }
    private bool loadCompilerDLL()
    {
      String DLLFileNameDx64 = "Compilerx64d.dll";
      String DLLFileNameRx64 = "Compilerx64.dll";
      String DLLFileNameDx86 = "Compilerx86d.dll";
      String DLLFileNameRx86 = "Compilerx86.dll";
      String processFullPath = Process.GetCurrentProcess().MainModule.FileName; // Regresa la ruta completa del proceso donde esta la dll

      /* Search for debug x64 */
      String[] upstr = new String[6];
      DirectoryInfo up = Directory.GetParent(processFullPath);
      for (int i = 0; i < upstr.Length; i++)
      {
        upstr[i] = up.FullName;
        up = Directory.GetParent(upstr[i]);
        /* Debug */
        if (currentAssemblyisDebug && currentAssemblyIsx64)
          DLLFullPath = upstr[i] + "\\CompilerUI\\x64\\Exe\\Debug\\" + DLLFileNameDx64;
        else if (currentAssemblyisDebug && !currentAssemblyIsx64)
          DLLFullPath = upstr[i] + "\\CompilerUI\\x86\\Exe\\Debug\\" + DLLFileNameDx86;
        /* Release */
        if (currentAssemblyisRelease && currentAssemblyIsx64)
          DLLFullPath = upstr[i] + "\\CompilerUI\\x64\\Exe\\Release\\" + DLLFileNameRx64;
        else if (currentAssemblyisRelease && !currentAssemblyIsx64)
          DLLFullPath = upstr[i] + "\\CompilerUI\\x86\\Exe\\Release\\" + DLLFileNameRx86;
      }
      //DLLFullPath = up6str + "\\Compiler\\x64\\Exe\\Debug\\" + DLLFileName;
      var DLL = Assembly.UnsafeLoadFrom(DLLFullPath);

      var DLLType = DLL.GetType("Compiler.Manager");
      compilerDLLInstance = Activator.CreateInstance(DLLType);
      isDLLLoaded = compilerDLLInstance != null;


      return isDLLLoaded;
    }

    void setTokenTable(string src)
    {
      for (int i = 0; i < src.Length; i++)
      {
        if (src[i] != '@')
        {
          str += src[i];
          //i++;
        }
        if (src[i + 1] == '@')
        {
          Words.Add(str);
          str = "";
          i++;
        }
        if (Words.Count == 3)
        {
          dataGridView1.Rows.Add(Words[0], Words[1], Words[2]);

          Words.Clear();
        }
      }
    }

    void setSymbolTable(string src)
    {
      for (int i = 0; i < src.Length; i++)
      {
        if (src[i] != '@')
        {
          str += src[i];
          //i++;
        }
        if (src[i + 1] == '@')
        {
          LSymbols.Add(str);
          str = "";
          i++;
        }
        if (LSymbols.Count == 7)
        {
          dataGridView2.Rows.Add(LSymbols[0], LSymbols[1], LSymbols[2], LSymbols[3], LSymbols[4], LSymbols[5], LSymbols[6]);

          LSymbols.Clear();
        }
      }
    }

    private void compileProgramToolStripMenuItem_Click(object sender, EventArgs e)
    {
      if (isDLLLoaded)
      {
        String[] output = compilerDLLInstance.compileProgram(textBox1.Text);
        // textBox2.Lines = output;
        String temp2 = output[0];
        textBox2.Text = temp2;

        String Tokens = output[1];                                      // Temporal String for the concatenated string of the tokens
        String Errors = output[2];                                      // Temporal String for the concatenated string of the tokens
        String Symbols = output[3];                                     // Temporal String for the concatenated string of the tokens
                                                                        //   textBox2.Text = "---------- Error List ----------";
        textBox2.Text = Errors;
        // Separate the string and get the values into the tokens grid
        setTokenTable(Tokens);
        setSymbolTable(Symbols);

      }
      else
      {
        string message = "Error loading the DLL!";
        string title = "CompilerUI";
        MessageBoxButtons buttons = MessageBoxButtons.OK;
        DialogResult result = MessageBox.Show(message, title, buttons, MessageBoxIcon.Error);
        return;
      }
    }

    private void Form1_Load(object sender, EventArgs e)
    {
      if (!loadCompilerDLL())
      {
        string message = "Error loading the DLL!";
        string title = "CompilerUI";
        MessageBoxButtons buttons = MessageBoxButtons.OK;
        DialogResult result = MessageBox.Show(message, title, buttons, MessageBoxIcon.Error);
        return;
      }
      isDLLLoaded = true;
    }

    private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
    {

    }

    private void textBox1_TextChanged(object sender, EventArgs e)
    {
      // Data = textBox1.Text;
    }

    private void textBox2_TextChanged(object sender, EventArgs e)
    {

    }

    private void label1_Click(object sender, EventArgs e)
    {
    }

    private void label2_Click(object sender, EventArgs e)
    {

    }

    private void label3_Click(object sender, EventArgs e)
    {

    }

    private void nuevoToolStripMenuItem_Click(object sender, EventArgs e)
    {
      string message = "Do you want to save changes to untitled?";
      string title = "CompilerUI";
      MessageBoxButtons buttons = MessageBoxButtons.YesNo;
      DialogResult result = MessageBox.Show(message, title, buttons);
      if (result == DialogResult.Yes)
      {
        GuardarComo();
      }
      else
      {
        // Do something  
        textBox1.Text = "";
      }
    }

    private void compileToolStripMenuItem_Click(object sender, EventArgs e)
    {

    }

    private void saveSimbolToolStripMenuItem_Click(object sender, EventArgs e)
    {


    }

    private void guardarToolStripMenuItem_Click(object sender, EventArgs e)
    {
      TextWriter SaveFile = new StreamWriter("C:\\Users\\personal\\Documents\\IDV17c\\Cuatri 6\\Compiladores\\CompilerUI\\demo.txt");
      SaveFile.Write(textBox1.Text);
      SaveFile.Close();
      System.Media.SystemSounds.Asterisk.Play();

      /* File Name in Label */
      // taking full path of a file 
      string strPath = "C:\\Users\\personal\\Documents\\IDV17c\\Cuatri 6\\Compiladores\\CompilerUI\\demo.txt";

      // initialize the value of filename 
      string filename = null;

      // using the method 
      filename = Path.GetFileName(strPath);

      label4.Text = filename;

      string text = System.IO.File.ReadAllText(strPath);
      textBox2.Text = text;
    }

    private void abrirToolStripMenuItem_Click(object sender, EventArgs e)
    {
      OpenFileDialog OpenFile = new OpenFileDialog();
      if (OpenFile.ShowDialog() == DialogResult.OK)
      {
        string FileData = File.ReadAllText(OpenFile.FileName);
        textBox1.Text = FileData;
        label4.Text = Path.GetFileName(OpenFile.FileName);
      }
    }

    private void guardarComoToolStripMenuItem_Click(object sender, EventArgs e)
    {
      GuardarComo();
    }

    void GuardarComo()
    {
      SaveFileDialog saveFileAs = new SaveFileDialog();
      saveFileAs.Filter = "Text File|*.txt|CPP File|*.cpp";
      saveFileAs.Title = "Save file as...";
      saveFileAs.ShowDialog();

      // If the file name is not an empty string open it for saving.  
      if (saveFileAs.FileName != "")
      {
        using (StreamWriter Data = new StreamWriter(saveFileAs.OpenFile()))
        {
          Data.Write(textBox1.Text);
        }
      }
    }

    private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
    {

    }

    private void label4_Click(object sender, EventArgs e)
    {
      // taking full path of a file 
      label4.Text = null;
      string strPath = "C:\\Users\\personal\\Documents\\IDV17c\\Cuatri 6\\Compiladores\\CompilerUI\\demo.txt";

      // initialize the value of filename 
      string filename = null;

      // using the method 
      filename = Path.GetFileName(strPath);

      label4.Text = filename;
    }


    private void salirToolStripMenuItem_Click(object sender, EventArgs e)
    {
      if (System.Windows.Forms.Application.MessageLoop)
      {
        // WinForms app
        System.Windows.Forms.Application.Exit();
      }
      else
      {
        // Console app
        System.Environment.Exit(1);
      }
    }

    private void archivoToolStripMenuItem_Click(object sender, EventArgs e)
    {

    }


  }
}
