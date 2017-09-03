using Android.App;
using Android.Widget;
using Android.OS;

namespace DoubliLinkedList_android
{
    [Activity(Label = "DoubliLinkedList_android", MainLauncher = true)]
    public class MainActivity : Activity
    {
        ListViewCustom listAdapter;
        CircularLinkedList List;
        ListView listView;

        Button InsertAtBegin;
        Button InsertAtEnd;
        Button DeleteAtBegin;
        Button DeleteAtEnd;

        TextView Value;
        protected override void OnCreate(Bundle savedInstanceState)
        {
            
            base.OnCreate(savedInstanceState);

            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.Main);

            List = new CircularLinkedList();
            listAdapter = new ListViewCustom(this, List.display());

            InsertAtBegin = FindViewById<Button>(Resource.Id.BtnInsertAtBegin);
            InsertAtEnd = FindViewById<Button>(Resource.Id.BtnInsertAtEnd);
            DeleteAtBegin = FindViewById<Button>(Resource.Id.BtnDeleteAtBegin);
            DeleteAtEnd = FindViewById<Button>(Resource.Id.BtnDeleteAtEnd);
            Value = FindViewById<TextView>(Resource.Id.ValueEditText);

            InsertAtBegin.Click += InsertAtBegin_Click;
            InsertAtEnd.Click += InsertAtEnd_Click;
            DeleteAtBegin.Click += DeleteAtBegin_Click;
            DeleteAtEnd.Click += DeleteAtEnd_Click;
        }

        private void DeleteAtEnd_Click(object sender, System.EventArgs e)
        {
            List.DeleteAtEnd();
            listAdapter = new ListViewCustom(this, List.display());
            listView.Adapter = listAdapter;
        }

        private void DeleteAtBegin_Click(object sender, System.EventArgs e)
        {
            List.DeleteAtBegin();
            listAdapter = new ListViewCustom(this, List.display());
            listView.Adapter = listAdapter;

        }

        private void InsertAtEnd_Click(object sender, System.EventArgs e)
        {
            try
            {
                List.InsertAtEnd(int.Parse(Value.Text));
                listAdapter = new ListViewCustom(this, List.display());
                Value.Text = "";
                listView.Adapter = listAdapter;
            }
            catch (System.Exception)
            {

                //throw;
            }

        }

        private void InsertAtBegin_Click(object sender, System.EventArgs e)
        {
            try
            {
                List.InsertAtBegin(int.Parse(Value.Text));
                listAdapter = new ListViewCustom(this, List.display());
                Value.Text = "";
                listView.Adapter = listAdapter;
            }
            catch (System.Exception)
            {

                //throw;
            }

        }

        protected override void OnResume()
        {
            base.OnResume();
            listView = FindViewById<ListView>(Resource.Id.listView);
            listView.Adapter = listAdapter;
        }
    }
}

