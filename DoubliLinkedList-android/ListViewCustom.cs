using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;

namespace DoubliLinkedList_android
{
    public class ListViewCustom : BaseAdapter<int>
    {
        int[] Items;
        Activity Context;
        public ListViewCustom(Activity context, int[] items) : base()
        {
            Context = context;
            Items = items;
        }

        public override int this[int position] => Items[position];

        public override int Count => Items.Length;

        public override long GetItemId(int position) => position;
        //{
        //    return position;
        //}

        public override View GetView(int position, View convertView, ViewGroup parent)
        {
            View view = convertView;
            if (view==null)
            {
                view = Context.LayoutInflater.Inflate(Resource.Layout.ListViewCustom, null);
                view.FindViewById<TextView>(Resource.Id.valueTxt).Text = Items[position].ToString();
            }
            return view;
        }
    }
}