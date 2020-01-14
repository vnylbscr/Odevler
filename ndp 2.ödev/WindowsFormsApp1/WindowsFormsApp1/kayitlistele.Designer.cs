namespace WindowsFormsApp1
{
    partial class kayitlistele
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
            this.rch_listele = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // rch_listele
            // 
            this.rch_listele.Location = new System.Drawing.Point(148, 108);
            this.rch_listele.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rch_listele.Name = "rch_listele";
            this.rch_listele.Size = new System.Drawing.Size(510, 377);
            this.rch_listele.TabIndex = 0;
            this.rch_listele.Text = "";
            // 
            // kayitlistele
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(891, 684);
            this.Controls.Add(this.rch_listele);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "kayitlistele";
            this.Text = "kayitlistele";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox rch_listele;
    }
}