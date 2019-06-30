namespace CompilerUI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.Linea = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Lexico = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Tipo = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.m_line = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.m_name = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.m_category = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.m_lenght = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.m_type = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.m_function = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label3 = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.archivoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.nuevoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.abrirToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.guardarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.guardarComoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.salirToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.compileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.compileProgramToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripSeparator();
            this.saveTokensToFileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveSimbolToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.optionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lexicalAnalysisToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.syntaxAnalysisToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.semanticAnalysisToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.noMeRepruebePorfaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.ControlDarkDark;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Linea,
            this.Lexico,
            this.Tipo});
            this.dataGridView1.Location = new System.Drawing.Point(1102, 51);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(368, 370);
            this.dataGridView1.TabIndex = 1;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // Linea
            // 
            this.Linea.FillWeight = 40F;
            this.Linea.HeaderText = "Line";
            this.Linea.Name = "Linea";
            this.Linea.ReadOnly = true;
            this.Linea.Width = 40;
            // 
            // Lexico
            // 
            this.Lexico.FillWeight = 55F;
            this.Lexico.HeaderText = "Lexem";
            this.Lexico.Name = "Lexico";
            this.Lexico.ReadOnly = true;
            this.Lexico.Width = 55;
            // 
            // Tipo
            // 
            this.Tipo.FillWeight = 110F;
            this.Tipo.HeaderText = "Type";
            this.Tipo.Name = "Tipo";
            this.Tipo.ReadOnly = true;
            this.Tipo.Width = 110;
            // 
            // textBox2
            // 
            this.textBox2.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.textBox2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox2.Font = new System.Drawing.Font("Consolas", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox2.ForeColor = System.Drawing.Color.White;
            this.textBox2.Location = new System.Drawing.Point(12, 467);
            this.textBox2.Multiline = true;
            this.textBox2.Name = "textBox2";
            this.textBox2.ReadOnly = true;
            this.textBox2.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox2.Size = new System.Drawing.Size(1458, 191);
            this.textBox2.TabIndex = 2;
            this.textBox2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(9, 447);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(51, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "Output";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(9, 676);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(93, 17);
            this.label2.TabIndex = 4;
            this.label2.Text = "Symbol Label";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // dataGridView2
            // 
            this.dataGridView2.BackgroundColor = System.Drawing.SystemColors.ControlDarkDark;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.m_line,
            this.m_name,
            this.m_category,
            this.m_lenght,
            this.m_type,
            this.m_function});
            this.dataGridView2.Location = new System.Drawing.Point(12, 696);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowTemplate.Height = 24;
            this.dataGridView2.Size = new System.Drawing.Size(1455, 170);
            this.dataGridView2.TabIndex = 5;
            this.dataGridView2.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView2_CellContentClick);
            // 
            // m_line
            // 
            this.m_line.HeaderText = "Line";
            this.m_line.Name = "m_line";
            // 
            // m_name
            // 
            this.m_name.HeaderText = "Name";
            this.m_name.Name = "m_name";
            // 
            // m_category
            // 
            this.m_category.HeaderText = "Category";
            this.m_category.Name = "m_category";
            // 
            // m_lenght
            // 
            this.m_lenght.HeaderText = "Lenght";
            this.m_lenght.Name = "m_lenght";
            // 
            // m_type
            // 
            this.m_type.HeaderText = "Data Type";
            this.m_type.Name = "m_type";
            // 
            // m_function
            // 
            this.m_function.FillWeight = 500F;
            this.m_function.HeaderText = "In function";
            this.m_function.Name = "m_function";
            this.m_function.Width = 500;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(1099, 31);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(55, 17);
            this.label3.TabIndex = 6;
            this.label3.Text = "Tokens";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.archivoToolStripMenuItem,
            this.compileToolStripMenuItem,
            this.optionsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1482, 28);
            this.menuStrip1.TabIndex = 7;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // archivoToolStripMenuItem
            // 
            this.archivoToolStripMenuItem.BackColor = System.Drawing.Color.Transparent;
            this.archivoToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.nuevoToolStripMenuItem,
            this.abrirToolStripMenuItem,
            this.guardarToolStripMenuItem,
            this.guardarComoToolStripMenuItem,
            this.toolStripMenuItem1,
            this.salirToolStripMenuItem});
            this.archivoToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.archivoToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Black;
            this.archivoToolStripMenuItem.Name = "archivoToolStripMenuItem";
            this.archivoToolStripMenuItem.Size = new System.Drawing.Size(71, 24);
            this.archivoToolStripMenuItem.Text = "Archivo";
            this.archivoToolStripMenuItem.Click += new System.EventHandler(this.archivoToolStripMenuItem_Click);
            // 
            // nuevoToolStripMenuItem
            // 
            this.nuevoToolStripMenuItem.Name = "nuevoToolStripMenuItem";
            this.nuevoToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.nuevoToolStripMenuItem.Text = "&Nuevo";
            this.nuevoToolStripMenuItem.Click += new System.EventHandler(this.nuevoToolStripMenuItem_Click);
            // 
            // abrirToolStripMenuItem
            // 
            this.abrirToolStripMenuItem.Name = "abrirToolStripMenuItem";
            this.abrirToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.abrirToolStripMenuItem.Text = "Abrir...";
            this.abrirToolStripMenuItem.Click += new System.EventHandler(this.abrirToolStripMenuItem_Click);
            // 
            // guardarToolStripMenuItem
            // 
            this.guardarToolStripMenuItem.Name = "guardarToolStripMenuItem";
            this.guardarToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.guardarToolStripMenuItem.Text = "Guardar";
            this.guardarToolStripMenuItem.Click += new System.EventHandler(this.guardarToolStripMenuItem_Click);
            // 
            // guardarComoToolStripMenuItem
            // 
            this.guardarComoToolStripMenuItem.Name = "guardarComoToolStripMenuItem";
            this.guardarComoToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.guardarComoToolStripMenuItem.Text = "Guardar Como";
            this.guardarComoToolStripMenuItem.Click += new System.EventHandler(this.guardarComoToolStripMenuItem_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(178, 6);
            // 
            // salirToolStripMenuItem
            // 
            this.salirToolStripMenuItem.Name = "salirToolStripMenuItem";
            this.salirToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.salirToolStripMenuItem.Text = "Salir";
            this.salirToolStripMenuItem.Click += new System.EventHandler(this.salirToolStripMenuItem_Click);
            // 
            // compileToolStripMenuItem
            // 
            this.compileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.compileProgramToolStripMenuItem,
            this.toolStripMenuItem2,
            this.saveTokensToFileToolStripMenuItem,
            this.saveSimbolToolStripMenuItem});
            this.compileToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.compileToolStripMenuItem.Name = "compileToolStripMenuItem";
            this.compileToolStripMenuItem.Size = new System.Drawing.Size(77, 24);
            this.compileToolStripMenuItem.Text = "Compile";
            this.compileToolStripMenuItem.Click += new System.EventHandler(this.compileToolStripMenuItem_Click);
            // 
            // compileProgramToolStripMenuItem
            // 
            this.compileProgramToolStripMenuItem.Name = "compileProgramToolStripMenuItem";
            this.compileProgramToolStripMenuItem.Size = new System.Drawing.Size(259, 26);
            this.compileProgramToolStripMenuItem.Text = "Compile Program (&F)";
            this.compileProgramToolStripMenuItem.Click += new System.EventHandler(this.compileProgramToolStripMenuItem_Click);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(256, 6);
            // 
            // saveTokensToFileToolStripMenuItem
            // 
            this.saveTokensToFileToolStripMenuItem.Name = "saveTokensToFileToolStripMenuItem";
            this.saveTokensToFileToolStripMenuItem.Size = new System.Drawing.Size(259, 26);
            this.saveTokensToFileToolStripMenuItem.Text = "Save tokens to file...";
            // 
            // saveSimbolToolStripMenuItem
            // 
            this.saveSimbolToolStripMenuItem.Name = "saveSimbolToolStripMenuItem";
            this.saveSimbolToolStripMenuItem.Size = new System.Drawing.Size(259, 26);
            this.saveSimbolToolStripMenuItem.Text = "Save Simbol Table to File...";
            this.saveSimbolToolStripMenuItem.Click += new System.EventHandler(this.saveSimbolToolStripMenuItem_Click);
            // 
            // optionsToolStripMenuItem
            // 
            this.optionsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.lexicalAnalysisToolStripMenuItem,
            this.syntaxAnalysisToolStripMenuItem,
            this.semanticAnalysisToolStripMenuItem});
            this.optionsToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.optionsToolStripMenuItem.Name = "optionsToolStripMenuItem";
            this.optionsToolStripMenuItem.Size = new System.Drawing.Size(73, 24);
            this.optionsToolStripMenuItem.Text = "Options";
            // 
            // lexicalAnalysisToolStripMenuItem
            // 
            this.lexicalAnalysisToolStripMenuItem.Checked = true;
            this.lexicalAnalysisToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.lexicalAnalysisToolStripMenuItem.Name = "lexicalAnalysisToolStripMenuItem";
            this.lexicalAnalysisToolStripMenuItem.Size = new System.Drawing.Size(202, 26);
            this.lexicalAnalysisToolStripMenuItem.Text = "Lexical Analysis";
            // 
            // syntaxAnalysisToolStripMenuItem
            // 
            this.syntaxAnalysisToolStripMenuItem.Checked = true;
            this.syntaxAnalysisToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.syntaxAnalysisToolStripMenuItem.Name = "syntaxAnalysisToolStripMenuItem";
            this.syntaxAnalysisToolStripMenuItem.Size = new System.Drawing.Size(202, 26);
            this.syntaxAnalysisToolStripMenuItem.Text = "Syntax Analysis";
            // 
            // semanticAnalysisToolStripMenuItem
            // 
            this.semanticAnalysisToolStripMenuItem.Checked = true;
            this.semanticAnalysisToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.semanticAnalysisToolStripMenuItem.Name = "semanticAnalysisToolStripMenuItem";
            this.semanticAnalysisToolStripMenuItem.Size = new System.Drawing.Size(202, 26);
            this.semanticAnalysisToolStripMenuItem.Text = "Semantic Analysis";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem,
            this.noMeRepruebePorfaToolStripMenuItem});
            this.helpToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(53, 24);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(245, 26);
            this.aboutToolStripMenuItem.Text = "About";
            // 
            // noMeRepruebePorfaToolStripMenuItem
            // 
            this.noMeRepruebePorfaToolStripMenuItem.Name = "noMeRepruebePorfaToolStripMenuItem";
            this.noMeRepruebePorfaToolStripMenuItem.Size = new System.Drawing.Size(245, 26);
            this.noMeRepruebePorfaToolStripMenuItem.Text = "No me repruebe porfa :(";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(12, 31);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(58, 17);
            this.label4.TabIndex = 8;
            this.label4.Text = "Source*";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.textBox1.Font = new System.Drawing.Font("Consolas", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.ForeColor = System.Drawing.Color.White;
            this.textBox1.Location = new System.Drawing.Point(12, 51);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox1.Size = new System.Drawing.Size(1084, 370);
            this.textBox1.TabIndex = 0;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(1482, 1055);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CompilerUI - Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.DataGridViewTextBoxColumn m_line;
        private System.Windows.Forms.DataGridViewTextBoxColumn m_name;
        private System.Windows.Forms.DataGridViewTextBoxColumn m_category;
        private System.Windows.Forms.DataGridViewTextBoxColumn m_lenght;
        private System.Windows.Forms.DataGridViewTextBoxColumn m_type;
        private System.Windows.Forms.DataGridViewTextBoxColumn m_function;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem archivoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem nuevoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem guardarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem guardarComoToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem salirToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem compileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem compileProgramToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem saveTokensToFileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveSimbolToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem optionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem lexicalAnalysisToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem syntaxAnalysisToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem semanticAnalysisToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ToolStripMenuItem abrirToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem noMeRepruebePorfaToolStripMenuItem;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Linea;
        private System.Windows.Forms.DataGridViewTextBoxColumn Lexico;
        private System.Windows.Forms.DataGridViewTextBoxColumn Tipo;
    }
}

