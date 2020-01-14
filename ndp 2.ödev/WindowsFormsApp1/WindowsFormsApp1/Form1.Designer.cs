namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.btn_kayitgir = new System.Windows.Forms.Button();
            this.btn_kayitlistele = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btn_kayitgir
            // 
            this.btn_kayitgir.Location = new System.Drawing.Point(102, 56);
            this.btn_kayitgir.Name = "btn_kayitgir";
            this.btn_kayitgir.Size = new System.Drawing.Size(75, 23);
            this.btn_kayitgir.TabIndex = 0;
            this.btn_kayitgir.Text = "kayıt gir";
            this.btn_kayitgir.UseVisualStyleBackColor = true;
            this.btn_kayitgir.Click += new System.EventHandler(this.btn_kayitgir_Click);
            // 
            // btn_kayitlistele
            // 
            this.btn_kayitlistele.Location = new System.Drawing.Point(102, 120);
            this.btn_kayitlistele.Name = "btn_kayitlistele";
            this.btn_kayitlistele.Size = new System.Drawing.Size(75, 23);
            this.btn_kayitlistele.TabIndex = 1;
            this.btn_kayitlistele.Text = "kayıt listele";
            this.btn_kayitlistele.UseVisualStyleBackColor = true;
            this.btn_kayitlistele.Click += new System.EventHandler(this.btn_kayitlistele_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(279, 260);
            this.Controls.Add(this.btn_kayitlistele);
            this.Controls.Add(this.btn_kayitgir);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btn_kayitgir;
        private System.Windows.Forms.Button btn_kayitlistele;
    }
}

