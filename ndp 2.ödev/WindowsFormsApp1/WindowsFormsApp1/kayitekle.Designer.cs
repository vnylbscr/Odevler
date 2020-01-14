namespace WindowsFormsApp1
{
    partial class kayitekle
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
            this.cmb_numrenk = new System.Windows.Forms.ComboBox();
            this.cmb_soyadrenk = new System.Windows.Forms.ComboBox();
            this.cmb_adrenk = new System.Windows.Forms.ComboBox();
            this.btn_kaydet = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txt_numara = new System.Windows.Forms.TextBox();
            this.txt_soyad = new System.Windows.Forms.TextBox();
            this.txt_ad = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // cmb_numrenk
            // 
            this.cmb_numrenk.FormattingEnabled = true;
            this.cmb_numrenk.Location = new System.Drawing.Point(251, 130);
            this.cmb_numrenk.Name = "cmb_numrenk";
            this.cmb_numrenk.Size = new System.Drawing.Size(121, 21);
            this.cmb_numrenk.TabIndex = 11;
            // 
            // cmb_soyadrenk
            // 
            this.cmb_soyadrenk.FormattingEnabled = true;
            this.cmb_soyadrenk.Location = new System.Drawing.Point(251, 86);
            this.cmb_soyadrenk.Name = "cmb_soyadrenk";
            this.cmb_soyadrenk.Size = new System.Drawing.Size(121, 21);
            this.cmb_soyadrenk.TabIndex = 12;
            // 
            // cmb_adrenk
            // 
            this.cmb_adrenk.FormattingEnabled = true;
            this.cmb_adrenk.Location = new System.Drawing.Point(251, 42);
            this.cmb_adrenk.Name = "cmb_adrenk";
            this.cmb_adrenk.Size = new System.Drawing.Size(121, 21);
            this.cmb_adrenk.TabIndex = 13;
            // 
            // btn_kaydet
            // 
            this.btn_kaydet.Location = new System.Drawing.Point(129, 223);
            this.btn_kaydet.Name = "btn_kaydet";
            this.btn_kaydet.Size = new System.Drawing.Size(75, 23);
            this.btn_kaydet.TabIndex = 10;
            this.btn_kaydet.Text = "kaydet";
            this.btn_kaydet.UseVisualStyleBackColor = true;
            this.btn_kaydet.Click += new System.EventHandler(this.btn_kaydet_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(45, 138);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(42, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "numara";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(45, 94);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "soyad";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(45, 48);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(19, 13);
            this.label1.TabIndex = 9;
            this.label1.Text = "ad";
            // 
            // txt_numara
            // 
            this.txt_numara.Location = new System.Drawing.Point(104, 131);
            this.txt_numara.Name = "txt_numara";
            this.txt_numara.Size = new System.Drawing.Size(100, 20);
            this.txt_numara.TabIndex = 4;
            // 
            // txt_soyad
            // 
            this.txt_soyad.Location = new System.Drawing.Point(104, 87);
            this.txt_soyad.Name = "txt_soyad";
            this.txt_soyad.Size = new System.Drawing.Size(100, 20);
            this.txt_soyad.TabIndex = 5;
            // 
            // txt_ad
            // 
            this.txt_ad.Location = new System.Drawing.Point(104, 42);
            this.txt_ad.Name = "txt_ad";
            this.txt_ad.Size = new System.Drawing.Size(100, 20);
            this.txt_ad.TabIndex = 6;
            // 
            // kayitekle
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(575, 447);
            this.Controls.Add(this.cmb_numrenk);
            this.Controls.Add(this.cmb_soyadrenk);
            this.Controls.Add(this.cmb_adrenk);
            this.Controls.Add(this.btn_kaydet);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txt_numara);
            this.Controls.Add(this.txt_soyad);
            this.Controls.Add(this.txt_ad);
            this.Name = "kayitekle";
            this.Text = "kayitekle";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cmb_numrenk;
        private System.Windows.Forms.ComboBox cmb_soyadrenk;
        private System.Windows.Forms.ComboBox cmb_adrenk;
        private System.Windows.Forms.Button btn_kaydet;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txt_numara;
        private System.Windows.Forms.TextBox txt_soyad;
        private System.Windows.Forms.TextBox txt_ad;
    }
}